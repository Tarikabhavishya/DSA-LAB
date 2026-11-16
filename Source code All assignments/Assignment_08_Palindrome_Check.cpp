#include <deque>
#include <iostream>
#include <string>
using namespace std;

bool isPalindrome(const string& input) {
    deque<char> characters(input.begin(), input.end());

    while (characters.size() > 1) {
        if (characters.front() != characters.back()) {
            return false;
        }
        characters.pop_front();
        characters.pop_back();
    }

    return true;
}

int main() {
    string input;
    cout << "Enter a string: ";
    if (!getline(cin, input)) {
        return 0;
    }

    if (isPalindrome(input)) {
        cout << "Palindrome\n";
    } else {
        cout << "Not a palindrome\n";
    }

    return 0;
}
