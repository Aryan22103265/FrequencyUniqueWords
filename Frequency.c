#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 100

void toLowerCase(char str[]) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

void removePunctuation(char str[]) {
    int i = 0, j = 0;
    while (str[i]) {
        if (isalpha(str[i]) || isspace(str[i])) {
            str[j++] = str[i];
        }
        i++;
    }
    str[j] = '\0';
}

int main() {
    char paragraph[10000];
    char words[MAX_WORDS][MAX_WORD_LENGTH];
    int wordCount[MAX_WORDS] = {0};
    int numWords = 0;

    printf("Enter a paragraph:\n");
    fgets(paragraph, sizeof(paragraph), stdin);

    toLowerCase(paragraph);
    removePunctuation(paragraph);

    char *word = strtok(paragraph, " ");
    while (word != NULL) {
        int found = 0;
        for (int i = 0; i < numWords; i++) {
            if (strcmp(words[i], word) == 0) {
                wordCount[i]++;
                found = 1;
                break;
            }
        }
        if (!found) {
            strcpy(words[numWords], word);
            wordCount[numWords]++;
            numWords++;
        }
        word = strtok(NULL, " ");
    }

    // Printing the frequencies of each word
    printf("\nWord frequencies:\n");
    for (int i = 0; i < numWords; i++) {
        printf("%s: %d\n", words[i], wordCount[i]);
    }

    return 0;
}
