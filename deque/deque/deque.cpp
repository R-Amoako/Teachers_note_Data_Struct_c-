// deque.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<deque>
#include<cctype>
#include<iomanip>

bool isPalindrom(std::string words) {
    bool isPalindrom = true;
    std::deque<char> word_deque{};
    std::deque<char> word_deque_{};
    for (auto s : words) {
        if (std::isalpha(s)) {
            word_deque.push_front(std::tolower(s));
            word_deque_.push_back(std::tolower(s));
        }   
    }

    //auto it = word_deque.begin();
    auto it_ = word_deque_.begin();

    for (char s : word_deque) {
        if (*it_ != s) return !isPalindrom;
        ++it_;
    }
    return isPalindrom;
}

bool is_matched_bracket(std::string expr) {

    //std::deque<char>
}

int main()
{
    std::cout << "'Do geese see God' is  a palindrom : " <<std::boolalpha<< isPalindrom("Do geese see God") << std::endl;
}

