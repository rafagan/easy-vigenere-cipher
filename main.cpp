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

#include <iostream>
#include <map>
#include <vector>

#include "cipher.h"

using namespace std;

int main() {
    printCipherMatrix();
    cout << endl;

    auto text = string("e+QCE)K<gjd{}-?D[}63~a#p$S-#4<%2%j)XV~8m_[]P;Vd)t7t@:M6;S");
    auto key = "jD7yeKQ,]udY$V5&Zyp%6MD4%^a-$_j}D>LdzqrYj['At+bv</cR:^-g8n";
    auto encrypted = encrypt(text, key, 1);
    auto decrypted = decrypt(encrypted, key, 1);

    cout << encrypted << endl;
    cout << decrypted << endl;
    cout << (decrypted == text ? "true" : "false") << endl;

    return 0;
}