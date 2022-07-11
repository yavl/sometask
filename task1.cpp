#include <iostream>
#include <unordered_map>

// An imaginary library meant to handle string manipulation
namespace ImaginaryLibrary {
    std::string lowercased(const std::string& text) {
        std::string lowercased;
        for (const auto& character : text) {
            lowercased += std::tolower(character);
        }
        return lowercased;
    }
};

std::string getConvertedText(const std::string& sourceText) {
    std::unordered_map<char, int> charactersCount;
    std::string lowercased = ImaginaryLibrary::lowercased(sourceText);
    for (const auto& character : lowercased) {
        ++charactersCount[character];
    }
    std::string convertedText = "";
    for (const auto& character : lowercased) {
        convertedText += charactersCount[character] == 1 ? "(" : ")";
    }
    return convertedText;
}

int main() {
    std::cout << getConvertedText("din") << std::endl;
    std::cout << getConvertedText("recede") << std::endl;
    std::cout << getConvertedText("Success") << std::endl;
    std::cout << getConvertedText("(( @") << std::endl;
}
