/*
1. Two Sum

Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.



Example 1:

Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
Example 2:

Input: nums = [3,2,4], target = 6
Output: [1,2]
Example 3:

Input: nums = [3,3], target = 6
Output: [0,1]

Constraints:

2 <= nums.length <= 10^4
-10^9 <= nums[i] <= 10^9
-10^9 <= target <= 10^9
Only one valid answer exists.
*/


#include <stdio.h>

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int *returnArr = malloc(2 * sizeof(int)); 
    *returnSize = 2; 

    for (int i = 0; i < numsSize - 1; i++) { 
        for (int j = i + 1; j < numsSize; j++) { 
            if (nums[i] + nums[j] == target) { 
                returnArr[0] = i;
                returnArr[1] = j; 
                return returnArr; 
            }
        }
    }
    return NULL; 
}
