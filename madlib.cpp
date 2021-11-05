#include <iostream>
#include <fstream>
#include <regex>

std::string inputFunction(std::string word){
    std::string in;
    std::cout << "Enter a: " << word << std::endl;
    std::cin >> in;
    return in;
}

int main(){

    std::ifstream inFile("example.txt");
    std::ofstream outFile("out.txt");

    std::string line;
    std::regex rgx("[{].*?}");
    while (getline(inFile, line)){
        std::smatch word;
        std::regex_search(line, word, rgx);
        std::string replaceWord = inputFunction(word[0]);
        line = std::regex_replace(line, rgx, replaceWord);
        outFile << line << "\n";
    }

    outFile.close();
    inFile.close();

    return 0;
}
