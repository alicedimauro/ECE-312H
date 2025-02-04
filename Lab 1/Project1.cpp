// ECE 312(H) PA1
// Alice Di Mauro
// ad55559
// Spring 2025
// Speight 

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>


// Helper function compareStrings to compare two strings by ASCII value
// Need to place this function first because if not printSortedWords won't recognize it and causes error

int compareStrings(char *str1, char *str2) {
    while (*str1 != '\0' && *str2 != '\0') {
        if (*str1 != *str2) {
            return *str1 - *str2; 
        }
        str1++;
        str2++;
    }
    // Handles cases where one string is a prefix of another: cat vs caterpillar
    return *str1 - *str2; 
}

void printSortedWords(char words[]) {
    char *wordArray[100]; // Array of pointers to hold up to 100 words
    char *currentWord = words; // Pointer to traverse the input string
    int wordCount = 0; // Counter

    // Split the input string into words
    while (*currentWord != '\0') {
        // Skip any leading whitespace
        while (*currentWord == ' ' || *currentWord == '\t' || *currentWord == '\n') {
            currentWord++;
        }

        if (*currentWord == '\0') 
        break; // End of string indicated by null

        // Store the start of the word so we know where true array starts 
        wordArray[wordCount] = currentWord;
        wordCount++; // Increment counter and element pointer

        // Move to the end of the current word
        while (*currentWord != ' ' && *currentWord != '\t' && *currentWord != '\n' && *currentWord != '\0') {
            currentWord++;
        }

        // Null-terminate the word so that it is its own independent string
        if (*currentWord != '\0') {
            *currentWord = '\0';
            currentWord++;
        }
    }

    // Sort the words using ASCII values (Bubble Sort)
    for (int i = 0; i < wordCount - 1; i++) {
        for (int j = 0; j < wordCount - i - 1; j++) {
            if (compareStrings(wordArray[j], wordArray[j + 1]) > 0) { 
                // Compare two adjacent words
                // If the first word has higher ASCII value than the second, swap them.
                char *temp = wordArray[j]; 
                wordArray[j] = wordArray[j + 1];
                wordArray[j + 1] = temp;
            }
        }
    }

    // Print and separate each word by a new line
    for (int i = 0; i < wordCount; i++) {
        printf("%s\n", wordArray[i]);
    }
}


