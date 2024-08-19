#include <iostream>
#include "RSA_Encryptor.h"


int main() {
    auto test = RSA_Encryptor(11, 23);
    test.data();
    test.encrypt("input.txt", "crypted.bin");
    std::cout << "\n===\n";
    test.decrypt("crypted.bin", "output.txt");
    return 0;
}
