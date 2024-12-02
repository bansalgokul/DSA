package coding_contests.leetcode.weekly_contest_426;
import java.util.Arrays;

class Solution {
    public int getLargestOutlier(int[] nums) {
        int n = nums.length;
        int totalSum = 0;
        Map<Integer, Integer> freq = new HashMap<Integer, Integer>();

        for(int i = 0; i < n; i++) {
            totalSum += nums[i];
            freq.put(nums[i], freq.getOrDefault(nums[i], 0) + 1);
        }

        int outlier = -1001;
        for(int i = 0; i < n; i++) {
            int currOutlier = nums[i];

            if(outlier != -1001 && currOutlier <= outlier) {
                continue;
            }

            int valueToFind = totalSum - currOutlier;
            if(Math.abs(valueToFind) % 2 == 1) {
                continue;
            }

            if(freq.get(valueToFind / 2) != null) {
                if(!(valueToFind / 2 == currOutlier && freq.get(valueToFind / 2) < 2)){
                    outlier = currOutlier;
                }
            }
        }

        return outlier;

    }
}

/**
 * Problem Statement:
 * Briefly summarize what the problem was asking for.
 * total n elements, n-2 are normal number, one is sum of n-2 normal numbers, one is outlier, give largest potentiol outlier

 * Approach Used:
 * Describe the approach or algorithm used to solve the problem.
 * Assume a number is outlier, total sum - outlier = 2 * num[index]

 * Time Complexity:
 * State the time complexity of your solution and why it is that.
 * O(n*logn) - iterate over every number * checking whether any number (total sum - outlier) / 2 exists or not.

 * Space Complexity:
 * State the space complexity of your solution and what contributes to it.
 * O(1) - no extra data structure used other than existing array.

 * Edge Cases:
 * Mention any special scenarios or edge cases considered.
 * if outlier and sum number is same, we need to check whether frequency of that number is > 1.

 * Lessons Learned:
 * Note any new concepts or insights gained from solving the problem.
 * -ve number can affect the % formula for even and odd.
 */