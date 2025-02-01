// ECE 312(H) PA1
// Alice Di Mauro
// ad55559
// Spring 2025
// Speight 

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

/*
    Wring a function to sort the words in 'words[]' and then print them to the console.
*/

// Helper function to compare two strings lexicographically
int compareStrings(char *str1, char *str2) {
    while (*str1 != '\0' && *str2 != '\0') {
        if (*str1 != *str2) {
            return *str1 - *str2; // ASCII difference, if positive difference then switch
        }
        str1++;
        str2++;
    }
    return *str1 - *str2; // Handle cases where one string is a prefix of another
}

void printSortedWords(char words[]) {
    //TODO: Your code here
    char *wordArray[100]; // Array of pointers to hold up to 100 words
    char *currentWord = words; // Pointer to traverse the input string
    int wordCount = 0; // Keeps count of how many words are extracted

    // Split the input string into words
    while (*currentWord != '\0') {
        // Skip any leading whitespace
        while (*currentWord == ' ' || *currentWord == '\t' || *currentWord == '\n') {
            currentWord++; // Skips spaces, tabs, and newlines until start of a word or end of string
        }

        if (*currentWord == '\0') break; // End of string

        // Store the start of the word
        wordArray[wordCount] = currentWord;
        wordCount++;

        // Move to the end of the current word
        while (*currentWord != ' ' && *currentWord != '\t' && *currentWord != '\n' && *currentWord != '\0') {
            currentWord++;
        }

        // Null-terminate the word and move to next word
        if (*currentWord != '\0') {
            *currentWord = '\0';
            currentWord++;
        }
    }

    // Sort the words using ASCII values (Bubble Sort)
    for (int i = 0; i < wordCount - 1; i++) {
        for (int j = 0; j < wordCount - i - 1; j++) {
            if (compareStrings(wordArray[j], wordArray[j + 1]) > 0) { 
// compare two adjacent words
//If the first word is lexicographically greater than the second, swap them.
                char *temp = wordArray[j];
                wordArray[j] = wordArray[j + 1];
                wordArray[j + 1] = temp;
            }
        }
    }

    // Print the sorted words
    for (int i = 0; i < wordCount; i++) {
        printf("%s\n", wordArray[i]);
    }
}


