package coding_contests.leetcode.weekly_contest_426;

class Solution {

    public static int getMaxNodes (ArrayList<List<Integer>> adjList, int k, int currNode, int n, boolean[] visited) {
        if(k == 0) {
            return 1;
        }
        if(k < 1) {
            return 0;
        }
        visited[currNode] = true;
        int output = 1;
        List<Integer> adjNodes = adjList.get(currNode);

        for(int node : adjNodes) {
            if(visited[node] != true) {
                output += getMaxNodes(adjList, k-1, node, n, visited);
            }
        }
        return output;
    }

    public static int getMaxNodes (ArrayList<List<Integer>> adjList, int k, int currNode, int n) {
        if(k == 0) {
            return 1;
        }
        if(k < 1) {
            return 0;
        }
        boolean[] visited = new boolean[n];
        visited[currNode] = true;
        int output = 1;
        List<Integer> adjNodes = adjList.get(currNode);

        for(int node : adjNodes) {
            output += getMaxNodes(adjList, k-1, node, n, visited);
        }
        return output;
    }

    public int[] maxTargetNodes(int[][] edges1, int[][] edges2, int k) {
        int n = edges1.length + 1;
        int m = edges2.length + 1;

        ArrayList<List<Integer>> adjList1 = new ArrayList<List<Integer>>();
        ArrayList<List<Integer>> adjList2 = new ArrayList<List<Integer>>();

        for(int i = 0; i < n; i++) {
            List<Integer> temp = new ArrayList<Integer>();
            adjList1.add(temp);
        }

        for(int i = 0; i < m; i++) {
            List<Integer> temp = new ArrayList<Integer>();
            adjList2.add(temp);
        }

        for(int i = 0; i < n-1; i++) {
            int u = edges1[i][0];
            int v = edges1[i][1];
            List<Integer> temp1 = adjList1.get(u);
            temp1.add(v);
            List<Integer> temp2 = adjList1.get(v);
            temp2.add(u);

            adjList1.set(u, temp1);
            adjList1.set(v, temp2);
        }

        for(int i = 0; i < m-1; i++) {
            int u = edges2[i][0];
            int v = edges2[i][1];

            List<Integer> temp1 = adjList2.get(u);
            temp1.add(v);
            List<Integer> temp2 = adjList2.get(v);
            temp2.add(u);

            adjList2.set(u, temp1);
            adjList2.set(v, temp2);
        }

        int maxNodes = 0;
        for(int i = 0; i < m; i++) {
            int value = getMaxNodes(adjList2, k-1, i, m);
            maxNodes = Math.max(maxNodes, value);
        }

        int[] output = new int[n];

        for(int i = 0; i < n; i++) {
            int value = getMaxNodes(adjList1, k, i, n) + maxNodes;
            output[i] = value;
        }

        return output;
    }
}

/**
 * Problem Statement:
 * Briefly summarize what the problem was asking for.
 * Return an array of n integers answer, where answer[i] is the maximum possible number of nodes target to node i of the first tree if you have to connect one node from the first tree to another node in the second tree.

 * Approach Used:
 * Describe the approach or algorithm used to solve the problem.
 * For tree 2 - we need to calculate the max nodes at a distance of k-1 for any node
 * For tree 1 - we need to get no of nodes at k distance from given node

 * Time Complexity:
 * State the time complexity of your solution and why it is that.
 * O(n*n) - no of nodes * get max nodes

 * Space Complexity:
 * State the space complexity of your solution and what contributes to it.
 * O(n2 + m2) - adjacency list of n nodes with n edges

 * Edge Cases:
 * Mention any special scenarios or edge cases considered.
 * case where k = 0 or k < 0

 * Lessons Learned:
 * Note any new concepts or insights gained from solving the problem.
 * Dont think too much about things like dp every time. start with brute force first always
 */