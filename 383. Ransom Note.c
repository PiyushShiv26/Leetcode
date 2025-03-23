/*
383. Ransom Note

Given two strings ransomNote and magazine, return true if ransomNote can be constructed by using the letters from magazine and false otherwise.

Each letter in magazine can only be used once in ransomNote.

 

Example 1:

Input: ransomNote = "a", magazine = "b"
Output: false
Example 2:

Input: ransomNote = "aa", magazine = "ab"
Output: false
Example 3:

Input: ransomNote = "aa", magazine = "aab"
Output: true
 

Constraints:

1 <= ransomNote.length, magazine.length <= 10^5
ransomNote and magazine consist of lowercase English letters.
*/

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool canConstruct(char* ransomNote, char* magazine) {
    int freq[26] = {0}; 


    for (int i = 0; magazine[i] != '\0'; i++) {
        freq[magazine[i] - 'a']++; //increment the frequency of the character
    }


    for (int i = 0; ransomNote[i] != '\0'; i++) {
        if (--freq[ransomNote[i] - 'a'] < 0) { //decrement the frequency of the character and check if it is less than 0
            return false; 
        }
    }

    return true;
}
