#include "Quotes/quotes.hpp"
#include <fstream>
#include "constants.hpp"
#include <filesystem>
#include <vector>

namespace CustomMenu::Quotes {
    std::vector<std::string> quotes = {
        "!bsr 25f",
        "Demo Version",
        "Performance Test",
        "Freeek Pattern",
        "ff9 - Smooth Criminal",
        "Electric Callboy music pack when?",
        "Amogus",
        "Sponsored by Livenessв„ў",
        "Beat Saber 2.0 confirmed?",
        "OST 8 Release 09.11.2024",
        "streamer play rap god",
        "Lstoast",
        "Can you play *insert random rush e meme map here*?",
        "Download the GaySabers mod!",
        "Reality Check Through The Skull",
        "Bandoot",
        "Tempex",
        "i am ob1cb",
        "$100 bills on easy"};

    std::vector<std::string> customQuotes = {"No Quotes Found!"};
    std::vector<std::string> selectedQuotes;

    void LoadQuotes() {
        selectedQuotes = quotes;
    }

    void LoadCustomQuotes() {
        std::string path = Constants::QuotePath;
        std::ifstream file(path);
        std::vector<std::string> tempQuotes;
        if (file.is_open()) {
            std::string line;
            while (std::getline(file, line)) {
                tempQuotes.push_back(line);
            }
            file.close();
        }

        if (tempQuotes.empty()) {
            selectedQuotes = customQuotes;
        } else {
            selectedQuotes = std::move(tempQuotes);
        }
    }

    std::string GetRandomQuote() {
        if (selectedQuotes.empty()) {
            return "No Quotes Found!";
        }
        return selectedQuotes[rand() % selectedQuotes.size()];
    }

    void EnsureFile() {
        std::string modPath = Constants::ModPath;
        if (!std::filesystem::exists(modPath)) {
            std::filesystem::create_directory(modPath);
        }

        std::string path = Constants::QuotePath;
        if (!std::filesystem::exists(path)) {
            std::ofstream file(path);
            file << "Quote 1\n";
            file << "Quote 2\n";
            file << "Quote 3\n";
            file << "Quote 4\n";
            file.close();
        }
    }
}
