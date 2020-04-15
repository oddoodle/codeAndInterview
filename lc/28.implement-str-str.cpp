/*
 * @lc app=leetcode id=28 lang=cpp
 *
 * [28] Implement strStr()
 */

// @lc code=start
#include<iostream>
using namespace std;

class Solution {
private:
    void get_next(string needle, int* next) {
        next[0] = -1;
        int length = (int)needle.length();
        int i = 0, j = -1;
        while(i < length-1) {
            if(j == -1 || needle[i] == needle[j]){
                i++;
                j++;
                next[i] = j; 
            }
            else {
                j = next[j];
            }
        }
    }

public:
    int strStr(string haystack, string needle) {
        int h_l = (int)haystack.length();
        int n_l = (int)needle.length();
        int* next = new int[n_l];
        if(needle != "") {
            get_next(needle, next);
            int i = 0,j = 0;
            while(i < h_l && j < n_l) {
                if(j == -1 || haystack[i] == needle[j]) {
                    i++;
                    j++;
                }
                else {
                    j = next[j];
                }
            }
            if(j == n_l)
                return i-j;
            else
            {
                return -1;
            }
            
        }
         
        return 0;
    }
};
// @lc code=end

