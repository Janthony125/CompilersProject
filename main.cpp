#include <iostream>
#include <regex>
#include <string>

using namespace std;
const string KEYWORDS = "alignas" 
                    "|alignof"
                    "|and"
                    "|and_eq"
                    "|asm"
                    "|atomic_cancel"
                    "|atomic_commit"
                    "|atomic_noexcept"
                    "|auto"
                    "|bitand"
                    "|bitor"
                    "|bool"
                    "|break"
                    "|case"
                    "|catch"
                    "|char"
                    "|char8_t"
                    "|char16_t"
                    "|char32_t"
                    "|class"
                    "|compl"
                    "|concept"
                    "|const"
                    "|consteval"
                    "|constexpr"
                    "|constinit"
                    "|const_cast"
                    "|continue"
                    "|co_await"
                    "|co_return"
                    "|co_yield"
                    "|decltype"
                    "|default"
                    "|delete"
                    "|do"
                    "|double"
                    "|dynamic_cast"
                    "|else"
                    "|enum"
                    "|explicit"
                    "|export"
                    "|extern"
                    "|false"
                    "|float"
                    "|for"
                    "|friend"
                    "|goto"
                    "|if"
                    "|inline"
                    "|int"
                    "|long"
                    "|mutable"
                    "|namespace"
                    "|new"
                    "|noexcept"
                    "|not"
                    "|not_eq"
                    "|nullptr"
                    "|operator"
                    "|or"
                    "|or_eq"
                    "|private"
                    "|protected"
                    "|public"
                    "|reflexpr"
                    "|register"
                    "|reinterpret_cast"
                    "|requires"
                    "|return"
                    "|short"
                    "|signed"
                    "|sizeof"
                    "|static"
                    "|static_assert"
                    "|static_cast"
                    "|struct"
                    "|switch"
                    "|synchronized"
                    "|template"
                    "|this"
                    "|thread_local"
                    "|throw"
                    "|true"
                    "|try"
                    "|typedef"
                    "|typeid"
                    "|typename"
                    "|union"
                    "|unsigned"
                    "|using"
                    "|virtual"
                    "|void"
                    "|volatile"
                    "|wchar_t"
                    "|while"
                    "|xor"
                    "|xor_eq";

bool isPunctuator(string ch){
    if(ch.length() != 1 || ch == "@") return false;
    regex punctuator("[[:blank:][:punct:]]");
    return regex_match(ch,punctuator);
}

bool isKeyword(const string& str){
    regex keywords(KEYWORDS);
    if(regex_match(str,keywords)){
        cout << str << " is a keyword" <<endl;
        return true;
    } 
    cout << str << " is not a keyword" <<endl;
    return false;
}

void parse(const string& file){
    int left = 0, right = 0;
    int len = file.length();
    // while(right <= len && left <= right){

    // }

}



int main() {

    cout << "Testing keywords" << endl;
    string tests = " +-*/\\,;><=()[]{}&|^?@abcAR";
    
    for(char c : tests){
        string test(1,c);
        cout << test 
        << (isPunctuator(test) ? " is a Punctuator":" is not a Punctuator") << endl;
    }
    return 0;

}