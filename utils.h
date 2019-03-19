#ifndef VIGENERE_CIPHER_UTILS_H
#define VIGENERE_CIPHER_UTILS_H

#include <vector>

std::vector<char> generateAlphabet();
std::vector<std::vector<int>> buildCipherMatrix(const std::vector<char>& alphabet, int salt);
void printCipherMatrix();

std::string encrypt(std::string text, std::string key, int salt);
std::string decrypt(std::string text, std::string key, int salt);

#endif //VIGENERE_CIPHER_UTILS_H
