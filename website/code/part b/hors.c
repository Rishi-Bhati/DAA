#include <stdio.h>
#include <string.h>

#define ALPHABET_SIZE 256

// Function to build the shift table for Horspool's algorithm
void buildShiftTable(char pattern[], int m, int shiftTable[]) {
    // Initialize all shifts to the length of the pattern
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        shiftTable[i] = m;
    }

    // For each character in the pattern except the last one,
    // set the shift value based on its position from the end
    for (int i = 0; i < m - 1; i++) {
        shiftTable[(unsigned char)pattern[i]] = m - 1 - i;
    }
}

// Function to perform Horspool's string matching algorithm
void horspoolSearch(char text[], char pattern[]) {
    int n = strlen(text);
    int m = strlen(pattern);
    int shiftTable[ALPHABET_SIZE];
    int i = m - 1; // Index in text

    // Build the shift table
    buildShiftTable(pattern, m, shiftTable);

    while (i < n) {
        int k = 0;

        // Compare pattern from right to left
        while (k < m && pattern[m - 1 - k] == text[i - k]) {
            k++;
        }

        if (k == m) {
            // Pattern found at position i - m + 1
            printf("Pattern found at index %d\n", i - m + 1);
            return;
        } else {
            // Shift the pattern based on the shift table
            i += shiftTable[(unsigned char)text[i]];
        }
    }

    // Pattern not found
    printf("Pattern not found in the text\n");
}

int main() {
    char text[1000], pattern[1000];

    // Prompt user to enter the text
    printf("Enter the text: ");
    fgets(text, sizeof(text), stdin);
    text[strcspn(text, "\n")] = '\0'; // Remove newline

    // Prompt user to enter the pattern
    printf("Enter the pattern to search: ");
    fgets(pattern, sizeof(pattern), stdin);
    pattern[strcspn(pattern, "\n")] = '\0'; // Remove newline

    // Call Horspool's search function
    horspoolSearch(text, pattern);

    return 0;
}
