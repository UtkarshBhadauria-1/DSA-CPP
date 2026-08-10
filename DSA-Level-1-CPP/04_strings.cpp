/*
DSA LEVEL 1 — STRINGS

Questions:
1. Find length of a string.
2. Count vowels and consonants.
3. Reverse a string.
4. Check whether a string is palindrome.
5. Convert lowercase to uppercase.
6. Count frequency of each character.
7. Find the first non-repeating character.
8. Remove spaces from a string.
9. Check whether two strings are anagrams.
10. Find the largest word in a sentence.
11. Reverse every word in a sentence.
12. Reverse the order of words in a sentence.
13. Check whether one string is a rotation of another.
14. Remove duplicate characters.
15. Find the longest common prefix.
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

// Q1
int q1_length(const string& s) {
    return s.length();
}

// Q2
pair<int, int> q2_vowelsConsonants(const string& s) {
    int vowels = 0, consonants = 0;

    for (char ch : s) {
        if (isalpha(ch)) {
            char c = tolower(ch);
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
                vowels++;
            else
                consonants++;
        }
    }

    return {vowels, consonants};
}

// Q3
string q3_reverse(string s) {
    reverse(s.begin(), s.end());
    return s;
}

// Q4
bool q4_palindrome(const string& s) {
    int i = 0, j = s.length() - 1;
    while (i < j) {
        if (s[i] != s[j]) return false;
        i++;
        j--;
    }
    return true;
}

// Q5
string q5_uppercase(string s) {
    for (char& ch : s)
        ch = toupper(ch);
    return s;
}

// Q6
void q6_frequency(const string& s) {
    int freq[256] = {0};

    for (char ch : s)
        freq[(unsigned char)ch]++;

    for (int i = 0; i < 256; i++) {
        if (freq[i] > 0)
            cout << char(i) << " : " << freq[i] << endl;
    }
}

// Q7
char q7_firstNonRepeating(const string& s) {
    int freq[256] = {0};

    for (char ch : s)
        freq[(unsigned char)ch]++;

    for (char ch : s) {
        if (freq[(unsigned char)ch] == 1)
            return ch;
    }

    return '\0';
}

// Q8
string q8_removeSpaces(const string& s) {
    string result;
    for (char ch : s) {
        if (ch != ' ')
            result += ch;
    }
    return result;
}

// Q9
bool q9_anagram(string a, string b) {
    if (a.length() != b.length()) return false;

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    return a == b;
}

// Q10
string q10_largestWord(const string& s) {
    string current, answer;

    for (char ch : s) {
        if (ch != ' ') {
            current += ch;
        } else {
            if (current.length() > answer.length())
                answer = current;
            current.clear();
        }
    }

    if (current.length() > answer.length())
        answer = current;

    return answer;
}

// Q11
string q11_reverseEachWord(string s) {
    int start = 0;

    for (int i = 0; i <= (int)s.length(); i++) {
        if (i == (int)s.length() || s[i] == ' ') {
            reverse(s.begin() + start, s.begin() + i);
            start = i + 1;
        }
    }

    return s;
}

// Q12
string q12_reverseWordOrder(string s) {
    reverse(s.begin(), s.end());

    int start = 0;
    for (int i = 0; i <= (int)s.length(); i++) {
        if (i == (int)s.length() || s[i] == ' ') {
            reverse(s.begin() + start, s.begin() + i);
            start = i + 1;
        }
    }

    return s;
}

// Q13
bool q13_rotation(string a, string b) {
    if (a.length() != b.length()) return false;
    return (a + a).find(b) != string::npos;
}

// Q14
string q14_removeDuplicates(const string& s) {
    bool seen[256] = {false};
    string result;

    for (char ch : s) {
        if (!seen[(unsigned char)ch]) {
            seen[(unsigned char)ch] = true;
            result += ch;
        }
    }

    return result;
}

// Q15
string q15_longestCommonPrefix(vector<string> words) {
    if (words.empty()) return "";

    string prefix = words[0];

    for (int i = 1; i < (int)words.size(); i++) {
        int j = 0;

        while (j < (int)prefix.length() &&
               j < (int)words[i].length() &&
               prefix[j] == words[i][j]) {
            j++;
        }

        prefix = prefix.substr(0, j);

        if (prefix.empty()) break;
    }

    return prefix;
}

int main() {
    // Test individual functions here.

    return 0;
}
