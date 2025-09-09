#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <filesystem>
#include <sstream>
#include <regex>

// I REPEAT, QT FRAMEWORK KILLED MY DOG
namespace fs = std::filesystem;

struct Song {
    std::string url;
    std::string start;
    std::string end;
    std::string fadeIn;
    std::string fadeOut;
    std::string tempFile;
};


int timeToSeconds(const std::string& t) {
    std::regex re(R"((?:(\d+):)?(\d+):(\d+))"); 
    std::smatch match;
    if (std::regex_match(t, match, re)) {
        int h = match[1].matched ? std::stoi(match[1]) : 0;
        int m = std::stoi(match[2]);
        int s = std::stoi(match[3]);
        return h * 3600 + m * 60 + s;
    } else {
        std::regex re2(R"((\d+):(\d+))");
        if (std::regex_match(t, match, re2)) {
            int m = std::stoi(match[1]);
            int s = std::stoi(match[2]);
            return m * 60 + s;
        }
    }
    return 0;
}

bool runCommand(const std::string& cmd) {
    int ret = std::system(cmd.c_str());
    if (ret != 0) {
        std::cerr << "Command failed: " << cmd << std::endl;
        return false;
    }
    return true;
}

bool processSong(Song& song, int index) {
    song.tempFile = "song_" + std::to_string(index) + ".mp3";

   
    std::ostringstream dlCmd;
    dlCmd << "yt-dlp --no-playlist -x --audio-format mp3 -o \"temp_audio_" 
          << index << ".mp3\" '" << song.url << "'";
    if (!runCommand(dlCmd.str())) return false;

   
    fs::path downloaded = "temp_audio_" + std::to_string(index) + ".mp3";
    if (!fs::exists(downloaded)) {
        std::cerr << "Downloaded file not found for song " << index << std::endl;
        return false;
    }

  
    int startSec = timeToSeconds(song.start);
    int endSec = timeToSeconds(song.end);
    int fadeInSec = std::stoi(song.fadeIn);
    int fadeOutSec = std::stoi(song.fadeOut);

    int fadeOutStart = endSec - fadeOutSec;
    if (fadeOutStart < startSec) fadeOutStart = startSec; 

    std::ostringstream ffCmd;
    ffCmd << "ffmpeg -y -i \"" << downloaded.string() << "\" "
          << "-ss " << song.start << " -to " << song.end << " "
          << "-af \"afade=t=in:ss=0:d=" << fadeInSec
          << ",afade=t=out:st=" << fadeOutStart << ":d=" << fadeOutSec << "\" "
          << "\"" << song.tempFile << "\"";

    if (!runCommand(ffCmd.str())) return false;

    fs::remove(downloaded);
    return true;
}

bool mergeSongs(const std::vector<Song>& songs, const std::string& outputFile) {
    std::ofstream listFile("merge_list.txt");
    if (!listFile) {
        std::cerr << "Failed to create merge list file." << std::endl;
        return false;
    }

    for (const auto& s : songs) {
        listFile << "file '" << fs::absolute(s.tempFile).string() << "'\n";
    }
    listFile.close();

    std::ostringstream mergeCmd;
    mergeCmd << "ffmpeg -y -f concat -safe 0 -i merge_list.txt -c copy \"" << outputFile << "\"";

    if (!runCommand(mergeCmd.str())) return false;

    for (const auto& s : songs) fs::remove(s.tempFile);
    fs::remove("merge_list.txt");

    return true;
}

int main() {
    std::vector<Song> songs;
    int n;
    std::cout << "Enter the number of songs: ";
    std::cin >> n;
    std::cin.ignore();

    for (int i = 0; i < n; ++i) {
        Song s;
        std::cout << "\nSong " << i+1 << " URL: ";
        std::getline(std::cin, s.url);

        std::cout << "Start time (HH:MM:SS or MM:SS): ";
        std::getline(std::cin, s.start);

        std::cout << "End time (HH:MM:SS or MM:SS): ";
        std::getline(std::cin, s.end);

        std::cout << "Fade-in duration (seconds): ";
        std::getline(std::cin, s.fadeIn);

        std::cout << "Fade-out duration (seconds): ";
        std::getline(std::cin, s.fadeOut);

        songs.push_back(s);
    }

    std::cout << "\nProcessing " << songs.size() << " songs...\n";

    for (size_t i = 0; i < songs.size(); ++i) {
        if (!processSong(songs[i], i+1)) {
            std::cerr << "Failed to process song " << i+1 << std::endl;
            return 1;
        }
    }

    std::string outputFile = "final_mixtape.mp3";
    if (!mergeSongs(songs, outputFile)) {
        std::cerr << "Failed to merge songs." << std::endl;
        return 1;
    }

    std::cout << "\nMixtape created successfully: " << outputFile << std::endl;
    return 0;
}
