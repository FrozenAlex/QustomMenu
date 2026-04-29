#pragma once

#include <string>
#include <vector>

namespace CustomMenu::Quotes {
extern std::vector<std::string> quotes;
extern std::vector<std::string> customQuotes;
extern std::vector<std::string> selectedQuotes;

void LoadQuotes();
void LoadCustomQuotes();
std::string GetRandomQuote();
void EnsureFile();
} // namespace CustomMenu::Quotes
