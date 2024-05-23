#include <iostream>
#include <string>
#include <cstdlib>

int main(int argc, char* argv[]) {
    if (argc != 7) {
        std::cerr << "Usage: " << argv[0] << " --string <string> --min_byte <min_byte> --max_byte <max_byte>\n";
        return 1;
    }

    std::string str;
    int min_byte;
    int max_byte;

    for (int i = 1; i < argc; i++) {
        if (std::string(argv[i]) == "--string") {
            str = argv[++i];
        } else if (std::string(argv[i]) == "--min_byte") {
            min_byte = std::stoi(argv[++i]);
        } else if (std::string(argv[i]) == "--max_byte") {
            max_byte = std::stoi(argv[++i]);
        }
    }

    if (min_byte > max_byte) {
        std::cerr << "Minimum byte cannot be greater than maximum byte.\n";
        return 1;
    }

    if (min_byte > str.length()) {
        std::cerr << "Minimum byte is greater than the string length.\n";
        return 1;
    }

    std::string substring = str.substr(min_byte, max_byte - min_byte);

    std::cout << substring << "\n";

    return 0;
}