# easy-vigenere-cipher
Simple functions to encrypt and decrypt in C++ using Vigenere Cipher method

Usage example:
```C++
constexpr auto text = "e+QCE)K<gjd{}-?D[}63~a#p$S-#4<%2%j)XV~8m_[]P;Vd)t7t@:M6;S";
constexpr auto key = "jD7yeKQ,]udY$V5&Zyp%6MD4%^a-$_j}D>LdzqrYj['At+bv</cR:^-g8n";
constexpr auto salt = -1; // Salt support to randomize even more the encryption
auto encrypted = encrypt(text, key, salt);
auto decrypted = decrypt(encrypted, key, salt);

cout << encrypted << endl;
cout << decrypted << endl;
cout << (decrypted == string(text) ? "true" : "false") << endl;
```