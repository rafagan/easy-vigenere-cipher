/******************************************************************************
*
* COPYRIGHT Ráfagan Sebástian de Abreu ALL RIGHTS RESERVED.
*
* This software can be copied, stored, distributed for any purpose. Just let the author know about it.
*
* This file was made available on https://github.com/rafagan and it is free
* to be restributed or used under Creative Commons license 2.5 br:
* http://creativecommons.org/licenses/by-sa/2.5/br/
*
*/

#ifndef VIGENERE_CIPHER_UTILS_H
#define VIGENERE_CIPHER_UTILS_H

#include <vector>

std::vector<char> generateAlphabet();
std::vector<std::vector<int>> buildCipherMatrix(const std::vector<char>& alphabet, int salt);
void printCipherMatrix();

std::string encrypt(std::string text, std::string key, int salt);
std::string decrypt(std::string text, std::string key, int salt);

#endif //VIGENERE_CIPHER_UTILS_H
