#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

// Function to split a string by a delimiter
std::vector<std::string> split(const std::string& line, char delimiter) {
    std::vector<std::string> fields;
    std::stringstream ss(line);
    std::string field;
    while (std::getline(ss, field, delimiter)) {
        fields.push_back(field);
    }
    return fields;
}

int main() {
    std::ifstream inputFile("input.txt"); // Replace with your input file name
    if (!inputFile) {
        std::cerr << "Error opening file." << std::endl;
        return 1;
    }

    std::string line;
    while (std::getline(inputFile, line)) {
        std::vector<std::string> fields = split(line, '|');
        
        // Example: Print all fields
        for (const auto& field : fields) {
            std::cout << field << " ";
        }
        std::cout << std::endl;
    }

    inputFile.close();
    return 0;
}
