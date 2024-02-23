#include <bits/stdc++.h>

using namespace std;

//int main() {
//    string s = "abcdef";
//
//    for (int i = 0; i < s.size() - 1; ++i) {
//        for (int j = i + 1; j < s.size(); ++j) {
//            if (s[i] == s[j]) {
//                cout << 0;
//            }
//        }
//    }
//    cout << 1;
//    return 0;
//}

#include <iostream>
#include <string>

std::string encrypt(const std::string &message) {
    std::string encrypted_message(message.size(), 0);

    encrypted_message[0] = message[0];

    for (size_t i = 1; i < message.size(); ++i) {
        encrypted_message[i] = message[i] + (message[i - 1] % 2);
    }

    return encrypted_message;
}

std::string decrypt(const std::string &encrypted_message) {
    std::string decrypted_message(encrypted_message.size(), 0);

    decrypted_message[0] = encrypted_message[0];

    for (size_t i = 1; i < encrypted_message.size(); ++i) {
        decrypted_message[i] = encrypted_message[i] - (encrypted_message[i - 1] % 2);
    }

    return decrypted_message;
}

int main() {
    std::string message = "hello world";

    std::string encrypted_message = encrypt(message);
    std::cout << "Encrypted message ---> " << encrypted_message << std::endl;

    std::string decrypted_message = decrypt(encrypted_message);
    std::cout << "Decrypted message ---> " << decrypted_message << std::endl;

    return 0;
}