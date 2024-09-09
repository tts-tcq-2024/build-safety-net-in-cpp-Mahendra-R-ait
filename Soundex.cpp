#include "Soundex.h"
#include <cctype>
#include <unordered_map>

static const std::unordered_map<char, char> soundexCodes {
        {'B', '1'}, {'F', '1'}, {'P', '1'}, {'V', '1'},
        {'C', '2'}, {'G', '2'}, {'J', '2'}, {'K', '2'}, {'Q', '2'}, {'S', '2'}, {'X', '2'}, {'Z', '2'},
        {'D', '3'}, {'T', '3'},
        {'L', '4'},
        {'M', '5'}, {'N', '5'},
        {'R', '6'}
};

char getSoundexCode(char character) {
    character = std::toupper(character);
    auto lookUpResult = soundexCodes.find(character);
    return (lookUpResult != soundexCodes.end()) ? lookUpResult->second : '0';
}

void appendSoundexCode(std::string& soundex, char code, char& prevCode) {
    if (code != '0' && code != prevCode) {
        soundex += code;
        prevCode = code;
    }
}

std::string processInitialCharacter(const std::string& Name) {
    std::string soundex;
    soundex += std::toupper(Name[0]);
    return soundex;
}

void processRemainingCharacters(const std::string& Name, std::string& soundex) {
    char prevCode = getSoundexCode(Name[0]);

    for (size_t i = 1; i < Name.length() && soundex.length() < 4; ++i) {
        char code = getSoundexCode(Name[i]);
        appendSoundexCode(soundex, code, prevCode);
    }
}

std::string generateSoundex(const std::string& Name) {
    if (Name.empty()) return "";

    std::string soundex = processInitialCharacter(Name);
    processRemainingCharacters(Name, soundex);

    soundex.resize(4, '0');
    return soundex;
}
