/*
7. Reverse Integer

Given a signed 32-bit integer x, return x with its digits reversed. If reversing x causes the value to go outside the signed 32-bit integer range [-2^31, 2^31 - 1], then return 0.

Assume the environment does not allow you to store 64-bit integers (signed or unsigned).

 

Example 1:

Input: x = 123
Output: 321
Example 2:

Input: x = -123
Output: -321
Example 3:

Input: x = 120
Output: 21
 

Constraints:

-2^31 <= x <= 2^31 - 1
*/

#include <stdio.h>
#include <limits.h>

int reverse(int x) {
    int result = 0;
    
    while (x != 0) {
        int pop = x % 10;
        
        // Check for overflow before updating result
        if (result > INT_MAX/10 || (result == INT_MAX/10 && pop > 7)) return 0;
        if (result < INT_MIN/10 || (result == INT_MIN/10 && pop < -8)) return 0;
        
        result = result * 10 + pop;
        x /= 10;
    }
    
    return result;
}

