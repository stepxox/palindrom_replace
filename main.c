#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

bool isPalindrome(char *str) {
    for (int i = 0; i < strlen(str); i++)
        if (str[i] != str[strlen(str) - i - 1] && !(str[i] == '_')) return false;
        else if (!(str[i] >= 'a' && str[i] <= 'z') && !(str[i] >= 'A' && str[i] <= 'Z')) {
            return true;
        }
    return false;
}

void lowerCase(char *str) {
    for (int i = 0; i < strlen(str); i++)
        str[i] = tolower(str[i]);
}

void replaceSpaces(char *str) {
    char a = '_';
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] == ' ')
            str[i] = a;
    }
    //printf("%s\n", str);
}

void removePunct(char *str) {
    for (int i = 0, j; str[i] != '\0'; ++i) {
        while (!(str[i] >= 'a' && str[i] <= 'z') && !(str[i] >= 'A' && str[i] <= 'Z') && !(str[i] == '\0') &&
               !(str[i] == '_')) {
            for (j = i; str[j] != '\0'; ++j) {
                str[j] = str[j + 1];
            }
        }
    }
    //printf("%s\n", str);
}

int main() {
    char str[100000];
    while (fgets(str, 100000, stdin) != NULL) {
        \

        lowerCase(str);
        replaceSpaces(str);
        removePunct(str);

        if (isPalindrome(str)) {
            printf("%s\n", str);
        } else {
            printf("Error");
        }
    }
    return 0;
}
