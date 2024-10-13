#include <iostream>
#include "RC4.h"
#include <chrono>
#include <cstring>
#include <fstream>

#define MAX_LENGTH 1024

int main() {
    auto start_time = std::chrono::high_resolution_clock::now();

    RC4 rc4;
    FILE *input_file = fopen("input.txt", "r");
    if (!input_file) {
        std::cerr << "Failed to open input file!" << std::endl;
        return 1;
    }
    char message[MAX_LENGTH];
    if (!fgets(message, sizeof(message), input_file)) {
        std::cerr << "Failed to read from input file!" << std::endl;
        fclose(input_file);
        return 1;
    }
    fclose(input_file);

    std::cout << "Original message: " << message << std::endl;

    char key[MAX_LENGTH];
    std::cout << "Enter the key: ";
    std::cin.getline(key, sizeof(key));
    std::cout<<std::endl;
    rc4.encryptDecrypt(message, strlen(message), key);
    std::cout << "Encrypted message: " << message << std::endl;

    FILE *output_file = fopen("output.txt", "w");
    if (!output_file) {
        std::cerr << "Failed to open output file!" << std::endl;
        return 1;
    }
    fputs(message, output_file);
    fclose(output_file);
    std::cout<<message<<std::endl;
    rc4.encryptDecrypt(message, strlen(message), key);
    std::cout << "Decrypted message: " << message << std::endl;

    auto end_time = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> execution_time = end_time - start_time;
    std::cout << "Time taken: " << execution_time.count() << " milliseconds\n";

    return 0;
}

