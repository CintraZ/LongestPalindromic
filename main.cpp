#include <iostream>
#include <string>
#include <algorithm>

using namespace std;


class Solution {
public:
    string longestPalindrome(string s) {
        int palin[s.size()][s.size()] = {0};
        int len = 0,left = 0,right = 0;

        for(int i = 0; i < s.size(); i++) {
            for(int j = 0; j < i; j++) {
                palin[j][i] = (s[i] == s[j]) && (i - j < 2 || palin[j + 1][i - 1]);
                if(palin[j][i] && len < i - j + 1) {
                    len = i - j + 1;
                    left = j;
                    right = i;
                }
            }
            palin[i][i] = 1;
        }
    return s.substr(left, right - left + 1);
    }
};

int main() {
    string s = "abbaa";
    Solution so;
    cout << so.longestPalindrome(s);

    return 0;
}