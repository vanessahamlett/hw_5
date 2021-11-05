#include <iostream>
#include <fstream>
#include <vector>
#include <regex>

void inputFunction(std::string word){
    std::string in;
    std::cout << " Enter a: " << word << std::endl;
    std::cin >> in;
}

int main(){
    std::cout << "Hello World" << std::endl;

    std::ifstream infile("example.txt");

    std::vector<std::string> wordsToReplace;

    std::string line;
    std::regex rgx("{.*?}");
    while (getline(infile, line)){
        std::smatch word;
        std::regex_search(line, rgx);
        //std::cout << (word[0]) << std::endl;
            //inputFunction(word[1]);
        
    }

    return 0;
}
