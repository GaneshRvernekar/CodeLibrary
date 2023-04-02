// There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

// For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
// Return true if you can finish all courses. Otherwise, return false.

 

// Example 1:

// Input: numCourses = 2, prerequisites = [[1,0]]
// Output: true
// Explanation: There are a total of 2 courses to take. 
// To take course 1 you should have finished course 0. So it is possible.



class Solution {
public:

bool isCycle(vector<int> g[], int i, vector<int> &vis) {
	if (vis[i] == 1) return true;
    if (vis[i] == 2) return false;
	if (vis[i] == 0) {
		vis[i] = 1;
		for (auto e : g[i]) {
			if (isCycle(g, e, vis)) return true;
		}
	}
	vis[i] = 2;
	return false;
}

bool canFinish(int n, vector<vector<int>>& prerequisites) {
	vector<int> g[n];
	for (auto e : prerequisites) {
		g[e[1]].push_back(e[0]);
	}
	vector<int> vis(n, 0);
	for (int i = 0; i < n; ++i) {
		if (isCycle(g, i, vis)) return false;
	}
	return true;
}
};