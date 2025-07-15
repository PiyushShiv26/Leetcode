/*
2000. Reverse Prefix of Word

Given a 0-indexed string word and a character ch, reverse the segment of word that starts at index 0 and ends at the index of the first occurrence of ch (inclusive). If the character ch does not exist in word, do nothing.

For example, if word = "abcdefd" and ch = "d", then you should reverse the segment that starts at 0 and ends at 3 (inclusive). The resulting string will be "dcbaefd".
Return the resulting string.

 

Example 1:

Input: word = "abcdefd", ch = "d"
Output: "dcbaefd"
Explanation: The first occurrence of "d" is at index 3. 
Reverse the part of word from 0 to 3 (inclusive), the resulting string is "dcbaefd".
Example 2:

Input: word = "xyxzxe", ch = "z"
Output: "zxyxxe"
Explanation: The first and only occurrence of "z" is at index 3.
Reverse the part of word from 0 to 3 (inclusive), the resulting string is "zxyxxe".
Example 3:

Input: word = "abcd", ch = "z"
Output: "abcd"
Explanation: "z" does not exist in word.
You should not do any reverse operation, the resulting string is "abcd".
 

Constraints:

1 <= word.length <= 250
word consists of lowercase English letters.
ch is a lowercase English letter.
*/

#include <stdio.h>
#include <string.h> 
#include <stdlib.h> 


char* reversePrefix(char* word, char ch) {
    int len = strlen(word);
    int place = -1; 
    for (int i = 0; i < len; i++) {
        if (word[i] == ch) {
            place = i;
            break; 
        }
    }
    if (place == -1) {
        char* returnStr = (char*)malloc(sizeof(char) * (len + 1)); 
        if (returnStr == NULL) {
            return NULL; 
        }
        strcpy(returnStr, word);
        return returnStr;
    }
    char* returnStr = (char*)malloc(sizeof(char) * (len + 1));
    if (returnStr == NULL) {
        return NULL; 
    }
    int j = 0;
    for (int i = place; i >= 0; i--) { 
        returnStr[j] = word[i];
        j++;
    }
    for (int i = place + 1; i < len; i++) {
        returnStr[j] = word[i];
        j++;
    }
    returnStr[j] = '\0';
    return returnStr;
}