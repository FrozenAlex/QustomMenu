#include "Quotes/quotes.hpp"
#include <fstream>
#include "constants.hpp"
#include <filesystem>

namespace CustomMenu::Quotes {
    void LoadQuotes() {
        selectedQuotes = quotes;
    }

    void LoadCustomQuotes() {
        std::string path = Constants::QuotePath;
        std::ifstream file(path);
        if (file.is_open()) {
            std::string line;
            while (std::getline(file, line)) {
                customQuotes.push_back(line);
            }
            file.close();
        }
        selectedQuotes = customQuotes;
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