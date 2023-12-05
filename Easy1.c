#include <stdio.h>
#include <string.h>

int lengthOfLastWord(char *s) {
    int length = 0;
    int i = strlen(s) - 1;

    // Skip trailing spaces
    while (i >= 0 && s[i] == ' ') {
        i--;
    }

    // Count characters of the last word
    while (i >= 0 && s[i] != ' ') {
        length++;
        i--;
    }

    return length;
}

int main() {
    char input[100]; // Assuming a maximum input length of 100 characters

    printf("Enter a string: ");
    scanf("%99[^\n]",input);



    int result = lengthOfLastWord(input);
    printf("Length of the last word: %d\n", result);

    return 0;
}
