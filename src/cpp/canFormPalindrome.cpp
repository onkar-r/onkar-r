#include <bits/stdc++.h>

using namespace std;

// Formula: A string can be converted into palindrome iff:
// 1. Even lengthed string: ALL its chars appear EVEN no. of times
// 2. Odd lengthed string : ALL its chars appear EVEN no. of times EXCEPT ONE CHAR
bool canFormPalindrome(const string& s) {
    cout << "\n\n>>> Input is: " << s << "\n";

    // Calculate the frequency of each char by inserting each char in a hash table by updating its frequency
    unordered_map<char, int> char_freq;
    for (auto c: s) {
        ++char_freq[c]; // Same char found? Update its frequency
    }

    for (const auto& c: char_freq) {
        std::cout << c.first << " -> " << c.second << "\n";
    }

    int oddFreqCount = 0;
    for (const auto& c: char_freq) {
        if ( !(c.second % 2 == 0) ) {
            ++oddFreqCount;
            cout << "char " << c.first << " doesn't appear even no. of times\n";
        }
    }
    if (oddFreqCount > 1) {
        return false;
    }
    return true;
}

int main() {
    vector<string> inputStrings = { "edified", "aabbccde" };
    for (auto str: inputStrings) {
        const bool b = canFormPalindrome(str);
        if (b) {
            cout << "String " << str << " can form a palindrome!\n";
        } else {
            cout << "Unfortunately, string " << str << " cannot form a palindrome!\n";
        }
    }

    return 0;
}