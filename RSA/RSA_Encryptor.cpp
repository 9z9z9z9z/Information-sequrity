//
// Created by rolya on 08.02.2024.
//

#include <iostream>
#include "RSA_Encryptor.h"


int mul_mod(int first, int second, int field) {
    return (first * second) % field;
}
int NOD(int a, int b) {
//    if (a > b) return NOD(a - b, b);
//    else if (a < b) return NOD(a, b - a);
//    else return a;
    for (int i = 2; i < b / 2; ++i) {
        if (b % i == 0 && a % i == 0) {
            return i;
        }
    }
    return 1;
}
int pow(const int &base, const int &degree, int field) {
    int ret = base;
    for (int i = 1; i < degree; ++i) {
        ret = mul_mod(ret, base, field);
    }
    return ret;
}

RSA_Encryptor::RSA_Encryptor(int p, int q) {
    n = p * q;
    int fi = eilerFunc(p, q);
    e = checkSimplisity(fi);
    int k = 1;
    while (((k * fi) + 1) % e != 0) {
        k++;
    }
    d = (k * fi + 1) / e;
}

void RSA_Encryptor::data() {
    std::cout << "n: " << n << " e: " << e << " d: " << d << std::endl;
}

int RSA_Encryptor::eilerFunc(int p, int q) {
    return (p - 1) * (q - 1);
}

int RSA_Encryptor::checkSimplisity(int end) {
    for (int i = 2; i < end / 2; ++i) {
        if (NOD(i, end) == 1) return i;
    }
}

int RSA_Encryptor::encrypt(const std::string &inputFilePath, const std::string &outputFilePath) {
    std::ifstream in(CURRENT_PATH + inputFilePath, std::ios::binary | std::ios::in);
    std::ofstream out(CURRENT_PATH + outputFilePath, std::ios::binary | std::ios::out);
    std::vector<unsigned char> buff;
    char byte;
    if (!in) {
        std::cerr << "Error with opening input file" << std::endl;
        return 1;
    }
    if (!out) {
        std::cerr << "Error with opening output file" << std::endl;
        return 1;
    }
    while (in.get(byte)) {
        buff.push_back(byte);
    }
    std::vector<int> encrypted;
    for (char m : buff) {
        int c = pow(static_cast<int>(m), e, n);
        encrypted.push_back(c);
        std::cout << "Read: " << static_cast<int>(m) << " " << m <<
                  " Calculated: " << c << " " << static_cast<char>(c) << std::endl;
        out << static_cast<char>(c);
    }
    return 0;
}

int RSA_Encryptor::decrypt(const std::string &inputFilePath, const std::string &outputFilePath) {
    std::ifstream in(CURRENT_PATH + inputFilePath, std::ios::binary | std::ios::in);
    std::ofstream out(CURRENT_PATH + outputFilePath, std::ios::binary | std::ios::out);
    std::vector<unsigned char> buff;
    unsigned char byte;
    if (!in) {
        std::cerr << "Error with opening input file" << std::endl;
        return 1;
    }
    if (!out) {
        std::cerr << "Error with opening output file" << std::endl;
        return 1;
    }
    while (in.get(reinterpret_cast<char &>(byte))) {
        buff.push_back(byte);
    }
    std::vector<int> decrypted;
    for (unsigned char m : buff) {
        int c = pow(static_cast<int>(m), d, n);
        decrypted.push_back(c);
        std::cout << "Read: " << m << " " << static_cast<int>(m) <<
                  " Calculated: " << c << " " << static_cast<char>(c) << std::endl;
        out << static_cast<char>(c);
    }
    return 0;
}