/*
412. Fizz Buzz

Given an integer n, return a string array answer (1-indexed) where:

answer[i] == "FizzBuzz" if i is divisible by 3 and 5.
answer[i] == "Fizz" if i is divisible by 3.
answer[i] == "Buzz" if i is divisible by 5.
answer[i] == i (as a string) if none of the above conditions are true.
 

Example 1:

Input: n = 3
Output: ["1","2","Fizz"]
Example 2:

Input: n = 5
Output: ["1","2","Fizz","4","Buzz"]
Example 3:

Input: n = 15
Output: ["1","2","Fizz","4","Buzz","Fizz","7","8","Fizz","Buzz","11","Fizz","13","14","FizzBuzz"]

Constraints:

1 <= n <= 10^4
*/

/**
 * Note: The returned array must be malloced, assume caller calls free().
*/


#include <stdio.h>
#include <stdlib.h>

char** fizzBuzz(int n, int* returnSize) {
    *returnSize = n;  
    char** result = (char**)malloc(n * sizeof(char*)); //array of strings
    char* fizz = "Fizz";
    char* buzz = "Buzz";
    char* fizzbuzz = "FizzBuzz";

    for (int i = 1; i <= n; i++) {
        if (i % 15 == 0) { //use this indsstead of i % 3 == 0 && i % 5 == 0
            result[i - 1] = fizzbuzz;  
        } else if (i % 3 == 0) {
            result[i - 1] = fizz;
        } else if (i % 5 == 0) {
            result[i - 1] = buzz;
        } else {
            result[i - 1] = (char*)malloc(5 * sizeof(char));  
            sprintf(result[i - 1], "%d", i); //convert int to string
        }
    }
    
    return result;
}

