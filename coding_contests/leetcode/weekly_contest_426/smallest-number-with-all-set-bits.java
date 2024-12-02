package coding_contests.leetcode.weekly_contest_426;

class Solution {
    public int smallestNumber(int n) {
        int numberOfShifts = 0;
        while(n > 1) {
            n = n >> 1;
            numberOfShifts++;
        }
        for(int i = 0; i < numberOfShifts; i++) {
            n = (n << 1) + 1;
        }
        return n;
    }
}

/**
 * Problem Statement:
 * Briefly summarize what the problem was asking for.
 * Return the smallest number x greater than or equal to n, such that the binary representation of x contains only set bits

 * Approach Used:
 * Describe the approach or algorithm used to solve the problem.
 * Right Shift to left till value reaches 1 and count the number of shifts. Then left shift 1 and add 1 n number of times.

 * Time Complexity:
 * State the time complexity of your solution and why it is that.
 * O(log n) - beacuse we are basically divinding by 1 every time and doing it twice. 2 log n base 2.

 * Space Complexity:
 * State the space complexity of your solution and what contributes to it.
 * O(1) - no data structure used.

 * Edge Cases:
 * Mention any special scenarios or edge cases considered.
 * No edge cases thought of

 * Lessons Learned:
 * Note any new concepts or insights gained from solving the problem.
 * Need to think about the problem more before jumping to a solution
 */