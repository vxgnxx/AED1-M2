/*
Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.

https://leetcode.com/problems/contains-duplicate/description/
*/

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

/* Brute Force - Estava gerando "Time Limit Exceeded" no Leet code, achei a solução atual pesquisando métodos pra resolver o problema
bool containsDuplicate(int* nums, int numsSize) {
    for(int i = 0; i < numsSize; i++){
        for(int j = i+1; j < numsSize; j++){
            if(nums[i] == nums[j]){
                return true;
            }
        }
    }
    
    return false;
}
*/

int cmp(const void *a, const void *b){
    return (*(int*)a - *(int*)b);
}

bool containsDuplicate(int* nums, int numsSize) {
    qsort(nums, numsSize, sizeof(int), cmp);

    for(int i = 1; i < numsSize; i++){
        if(nums[i] == nums[i-1]){
            return true;
        }
    }
    return false;
}

int main(void){
    int nums1[] = {1, 2, 3, 4, 5, 6, 7, 8, 0};   
    int nums2[] = {1, 2, 3, 4, 5, 1};            
    int nums3[] = {1, 1, 1, 1, 1};               
    int nums4[] = {10, 20, 30, 40};
    int *numslist[] = {nums1, nums2, nums3, nums4};
    int sizes[] = {9, 6, 5, 4};

    for(int i = 0; i < 4; i++){
        bool x = containsDuplicate(numslist[i], sizes[i]);
        printf("%d\n", x);
    }

}