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


#include "cipher.h"

#include <iostream>
#include <sstream>

using namespace std;

int FIRST_ASCII = 32;
int ASCII_SUPPORTED_SIZE = 127 - 32;

vector<char> generateAlphabet() {
    vector<char> alphabet;
    alphabet.reserve(static_cast<unsigned long>(ASCII_SUPPORTED_SIZE));
    for(char i = 0; i <= ASCII_SUPPORTED_SIZE; i++) {
        alphabet.push_back(static_cast<char>(FIRST_ASCII + i));
    }

    return alphabet;
}

vector<vector<int>> buildCipherMatrix(const vector<char>& alphabet, int salt) {
    vector<vector<int>> matrix;
    for(int i = 0; i < alphabet.size(); i++) {
        matrix.emplace_back();
        for(int j = 0; j < alphabet.size(); j++) {
            matrix[i].push_back((j + i * salt) % ASCII_SUPPORTED_SIZE);
        }
    }

    return matrix;
}

void printCipherMatrix() {
    auto matrix = buildCipherMatrix(generateAlphabet(), 1);
    cout << "   ";
    for(int letter: generateAlphabet()) {
        cout << char(letter);
    }
    cout << endl;

    for(int i = 0; i < matrix.size(); i++) {
        cout << char(i + FIRST_ASCII) << ": ";
        for(int j : matrix[i]) {
            cout << char(j + FIRST_ASCII);
        }
        cout << endl;
    }
}

char getLetterFromMatrix(char letterX, char letterY, int salt) {
    return static_cast<char>((letterY + letterX + salt - 2 * FIRST_ASCII) % ASCII_SUPPORTED_SIZE + FIRST_ASCII);
}

char getLetterYFromMatrix(char letterX, char letter, int salt) {
    auto result = letter - letterX - salt;
    while(result < 0) {
        result += ASCII_SUPPORTED_SIZE;
    }

    return static_cast<char>(FIRST_ASCII + result);
}

string encrypt(string text, string key, int salt) {
    stringstream builder;
    int count = 0;
    for(char letterY: text) {
        char letterX = key[count++ % key.size()];
        builder << getLetterFromMatrix(letterX, letterY, salt);
    }
    return builder.str();
}

string decrypt(string text, string key, int salt) {
    stringstream builder;
    int count = 0;
    for(char letter: text) {
        char letterX = key[count++ % key.size()];
        builder << getLetterYFromMatrix(letterX, letter, salt);
    }
    return builder.str();
}