#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int longestValidParentheses(const string& s) {
    int maxLen = 0, left = 0, right = 0;

    for (int i = 0; i < (int)s.size(); i++) {
        if (s[i] == '(') {
            left++;
        } else {
            right++;
        }

        if (left == right) {
            maxLen = max(maxLen, 2 * right);
        } else if (right > left) {
            left = 0;
            right = 0;
        }
    }

    left = 0;
    right = 0;

    for (int i = (int)s.size() - 1; i >= 0; i--) {
        if (s[i] == '(') {
            left++;
        } else {
            right++;
        }

        if (left == right) {
            maxLen = max(maxLen, 2 * left);
        } else if (left > right) {
            left = 0;
            right = 0;
        }
    }

    return maxLen;
}

int main() {
    string s;

    cout << "Enter string: ";
    cin >> s;

    cout << "Longest valid parentheses length: "<< longestValidParentheses(s) << endl;

    return 0;
}
