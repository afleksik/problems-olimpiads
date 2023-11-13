#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

// std::string_view
std::vector<u_int8_t> encrypt(const std::string &message) {
    std::vector<u_int8_t> ct(message.size());
    ct[0] = message[0];
    for (int i = 1; i < ct.size(); ++i) {
        ct[i] = message[i] ^ ct[i - 1];
    }
    return ct;
}

std::vector<u_int8_t> decrypt(std::vector<u_int8_t> enc) {
    std::vector<u_int8_t> ct(enc.size());
    ct[0] = enc[0];
    for (int i = 1; i < ct.size(); ++i) {
        ct[i] = (enc[i] ^ enc[i - 1]);
    }
    return ct;
}

int main() {
    std::string to_enc;
    std::vector<u_int8_t> enc;
    std::vector<u_int8_t> dec;

    //std::cin >> to_enc;

    //enc = encrypt(to_enc);

    //std::cout << "encrypted:\n";

    //for (int i = 0; i < enc.size(); ++i) {
    //    std::cout << std::hex << (int)to_enc[i] << " ---> "<< std::hex << (int)enc[i] << std::endl;
    //}

    //std::cout << "-------" << std::endl;

    dec = decrypt({0x63, 0x0A, 0x7A, 0x12, 0x77, 0x05});
    
    std::cout << "decrypted:\n";
    for (int j = 0; j < dec.size(); ++j) {
        std::cout << dec[j];
    }
    std::cout << std::endl;
    return 0;
}
