class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adjList(numCourses); // Initialize adjList with numCourses
        
        vector<int> indegree(numCourses, 0);
        for (const auto& prereq : prerequisites) {
            int course = prereq[0];
            int prereqCourse = prereq[1];
            indegree[course]++;
            adjList[prereqCourse].push_back(course);
        }
        
        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0)
                q.push(i);
        }
        
        int count = 0;
        while (!q.empty()) {
            int front = q.front();
            q.pop();
            count++;
            for (auto val : adjList[front]) {
                if (--indegree[val] == 0)
                    q.push(val);
            }
        }
        
        return count == numCourses;
    }
};













