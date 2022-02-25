#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

bool checkAnagram(char[], char[]);
bool isInAlphabet(char, char[]);
void charFrequency(char[], char[]);

int main() {
    char str1[100], str2[100];
    bool isAnagram = false;

    if (scanf("%s", str1));
    if (scanf("%s", str2));

    isAnagram = checkAnagram(str1, str2);

    if (isAnagram) {
        printf("Yes");
    } else {
        printf("No");
    }

    return 0;
}

bool checkAnagram(char str1[], char str2[]) {
    int charCount1[26] = {0}, charCount2[26] = {0};
    char englishAlphabet[26] = {
        'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 
        'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 
        'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 
        'y', 'z'
    };
    bool isInEnglishAlphabet;
    int i = 0;

    while (str1[i] != '\0') {
        char char_temp = tolower(str1[i]);
        isInEnglishAlphabet = isInAlphabet(char_temp, englishAlphabet);

        if (isInEnglishAlphabet) {
            charCount1[char_temp - 'a']++;
            i++;
        } else {
            continue;
        }
    }

    i = 0;

    while (str1[i] != '\0') {
        char char_temp = tolower(str2[i]);
        isInEnglishAlphabet = isInAlphabet(char_temp, englishAlphabet);

        if (isInEnglishAlphabet) {
            charCount2[char_temp - 'a']++;
            i++;
        } else {
            continue;
        }
    }

    for (int i = 0; i < 26; i++) {
        if (charCount1[i] != charCount2[i]) return false;
    }

    return true;
    
    // charFrequency(str1, charCount1);
}

bool isInAlphabet(char c, char englishAlphabet[26]) {
    for (int i = 0; i < 26; i++) {
        if (c == englishAlphabet[i]) return true;
    }

    return false;
}

void charFrequency(char str[], char charCount[]) {
    int i = 0;

    while (str[i] != "\0") {
        charCount[str[i] - 'a']++;
        i++;
    }
}
