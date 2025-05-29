/*
125. Valid Palindrome

A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.

Given a string s, return true if it is a palindrome, or false otherwise.

 

Example 1:

Input: s = "A man, a plan, a canal: Panama"
Output: true
Explanation: "amanaplanacanalpanama" is a palindrome.
Example 2:

Input: s = "race a car"
Output: false
Explanation: "raceacar" is not a palindrome.
Example 3:

Input: s = " "
Output: true
Explanation: s is an empty string "" after removing non-alphanumeric characters.
Since an empty string reads the same forward and backward, it is a palindrome.
 

Constraints:

1 <= s.length <= 2 * 10^5
s consists only of printable ASCII characters.
*/

#include <stdbool.h>
#include <ctype.h>
#include <stdlib.h>
bool isPalindrome(char* s) {
    char *new = malloc(strlen(s) + 1); 
    int j = 0;

    for (int i = 0; s[i] != '\0'; i++) {
        if (isalnum(s[i])) {
            new[j++] = tolower(s[i]);
        }
    }
    new[j] = '\0';  

    int left = 0, right = j - 1;
    while (left < right) {
        if (new[left] != new[right]) {
            free(new);
            return false;
        }
        left++;
        right--;
    }

    free(new);
    return true;
}
