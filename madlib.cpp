#include <iostream>
#include <fstream>
#include <regex>

std::string inputFunction(std::string word){
    std::string in;
    std::cout << "Enter a " << word << ": ";
    std::cin >> in;
    return in;
}

int main(){

    std::ifstream inFile("example.txt");
    std::ofstream outFile("out.txt");

    std::string line;
    std::regex rgx("[{].*?[}]");
    while (getline(inFile, line)){
        std::smatch word;
        while(std::regex_search(line, word, rgx)) {
            std::string replaceWord = inputFunction(word[0]);
            line = std::regex_replace(line, rgx, replaceWord, std::regex_constants::format_first_only); 
        }
        outFile << line << "\n";
    }

    outFile.close();
    inFile.close();

    return 0;
}
