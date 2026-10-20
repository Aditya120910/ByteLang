#include <iostream>
#include <cstdint>
#include <string>
#include <fstream>

uint8_t memory = 0;

int main(int argc, char*argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <file>\n";
        return 1;
    }
    std::string filename = argv[1];
    if (filename.size() < 3 ||
        filename.substr(filename.size() - 3) != ".bl") {
        std::cerr << "ERROR: File must have a .bl extension\n";
        return 1;
    }
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error: Could not open file: " << filename << '\n';
        return 1;
    }
    std::string arr;
    while (std::getline(file, arr)) {
        for (std::size_t i = 0; i < arr.size(); i++) {
            if(arr[i] == '+') {
                memory += 1;
            } else if (arr[i] == '-') {
                memory -= 1;
            } else if (arr[i] == '.') {
                std::cout << static_cast<char>(memory);
            } else if (arr[i] == '*') {
                memory = 0;
            } else {
                continue;
            }
        }
    }
    return 0;
}
