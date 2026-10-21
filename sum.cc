#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

int main() {
    // Open the input file
    std::ifstream inputFile("data.txt");
    if (!inputFile) {
        std::cerr << "Error: Could not open 'data.txt'" << std::endl;
        return 1;
    }

    // Open the output file
    std::ofstream outputFile("output.txt");
    if (!outputFile) {
        std::cerr << "Error: Could not create or open 'output.txt'" << std::endl;
        inputFile.close();
        return 1;
    }

    std::string currentLine;
    int lineCount = 0;

    // Process the file line by line until the end of the file
    while (std::getline(inputFile, currentLine)) {
        lineCount++;
        std::stringstream ss(currentLine);
        double num1 = 0.0, num2 = 0.0;

        // Try to extract exactly two numbers from the current line
        if (ss >> num1 >> num2) {
            double sum = num1 + num2;
            outputFile << "Line " << lineCount << " Sum: " << sum << std::endl;
        } else { continue; }
    }

    // Close both files
    inputFile.close();
    outputFile.close();

    std::cout << "Successfully processed " << lineCount << " lines. Results saved to 'output.txt'." << std::endl;

    return 0;
}
