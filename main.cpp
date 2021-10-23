#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <vector>
#include <regex>
using namespace std;

bool isKeyword(const string& str){
    string keywords[32] = {"auto","break","case","char","const","continue","default","do","double","else","enum","extern","float","for","goto","if","int","long","register","return","short","signed","sizeof","static","struct","switch","typedef","union","unsigned","void","volatile","while"};
    
    for(int i = 0; i < 32; ++i){
        if(keywords[i] == str){
            cout << str << " is a keyword\n";
            return true;
        }
    }
    return false;
}



bool isOperator(const char& str){
    char operators[] = "+-*/%=><";
    for(int i = 0; i < 8; ++i) {
        if(str == operators[i]){
            return true;
        }
    }
    return false;
}

bool isSeparator(const char& ch) {
    char separator[] = "{}()[]";
    for(int i = 0; i < 6; i++){
        if(separator[i] == ch){
            return true;
        }
    }
    return false;
}

bool isAlnum(const string& str){
    for(char c: str){
        if(!isalnum(c)) return false;
    }
    return true;
}

void identify(const string& currentToken) {
    if(!isKeyword(currentToken) && currentToken != ""){
        if(isalpha(currentToken[0]) && isAlnum(currentToken)){
            cout << currentToken << " is an identifier\n";
        } else if(regex_match(currentToken,regex("[[:digit:]]+"))){
            cout << currentToken << " is an INT value\n";
        } else if(regex_match(currentToken,regex("[+-]?([0-9]*[.])?[0-9]+"))){
            cout << currentToken << " is a FlOAT value\n";
        }
    }
}
int main() {
    char line[20];
    std::ifstream programFile;
    programFile.open("test.txt");
    if (programFile.fail()) {
        std::cerr << "Unable to open file for reading." << std::endl;
        exit(1);
    }
    char nextToken;
    string currentToken = "";
    while (!programFile.eof()) {
        //std::cout << nextToken << std::endl;
        nextToken = programFile.get();
        // cout << "Current token: " << nextToken << "\n";
        if(isalnum(nextToken) || nextToken == '.'){
            currentToken += nextToken;
        }
        else if(isSeparator(nextToken)){
            identify(currentToken);
            cout << nextToken << " is a separator\n";
            currentToken = "";
        }
        else if(isOperator(nextToken)){
            identify(currentToken);
            cout << nextToken << " is a operator\n";
            currentToken = "";
        }
        else if(nextToken == ' ' || nextToken == '\n' || nextToken == ';'){
            identify(currentToken);
            currentToken = "";
        }
        
    }
    
    identify(currentToken);
    programFile.close();
    return 0;
}

