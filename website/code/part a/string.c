#include <stdio.h>
#include <string.h>

// Function to perform brute force string matching
// This function searches for all occurrences of a pattern in a text
void bruteForce(char text[], char pattern[]) {
    // Get the length of the text string
    int n = strlen(text);
    
    // Get the length of the pattern string
    int m = strlen(pattern);
    
    // Variable to track if pattern was found at least once
    int found = 0;
    
    // Outer loop: iterate through each possible starting position in the text
    // We only need to check positions up to n-m because beyond that, 
    // there aren't enough characters left to match the pattern
    for (int i = 0; i <= n - m; i++) {
        // Assume pattern matches at this position
        int match = 1;
        
        // Inner loop: check if pattern matches at current position
        // Compare each character of pattern with corresponding character in text
        for (int j = 0; j < m; j++) {
            // If characters don't match, set match flag to 0 and break inner loop
            if (text[i + j] != pattern[j]) {
                match = 0;
                break;
            }
        }
        
        // If match flag is still 1, pattern was found at position i
        if (match == 1) {
            printf("Pattern found at position %d\n", i);
            found = 1;
        }
    }
    
    // If pattern was not found anywhere in the text
    if (found == 0) {
        printf("Pattern not found in the text\n");
    }
}

// Main function - entry point of the program
int main() {
    // Declare arrays to store the text and pattern strings
    // Size 100 allows for reasonably long strings
    char text[100];
    char pattern[100];
    
    // Prompt user to enter the text string
    printf("Enter the text string: \n");
    // Read the text string from user input
    scanf("%s", text);
    
    // Prompt user to enter the pattern to search for
    printf("Enter the pattern to search: \n");
    // Read the pattern string from user input
    scanf("%s", pattern);
    
    // Display the text and pattern for confirmation
    printf("Text: %s\n", text);
    printf("Pattern: %s\n", pattern);
    
    // Call the brute force function to search for the pattern in the text
    bruteForce(text, pattern);
    
    // Return 0 to indicate successful program execution
    return 0;
}
