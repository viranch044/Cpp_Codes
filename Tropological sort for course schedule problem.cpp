// There are a total of n courses you have to take, labeled from 0 to n-1.

// Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]

// Given the total number of courses and a list of prerequisite pairs, return the ordering of courses you should take to finish all courses.

// There may be multiple correct orders, you just need to return one of them. If it is impossible to finish all courses, return an empty array.

// Example 1:

// Input: 2, [[1,0]] 
// Output: [0,1]
// Explanation: There are a total of 2 courses to take. To take course 1 you should have finished   
//              course 0. So the correct course order is [0,1] .
// Example 2:

// Input: 4, [[1,0],[2,0],[3,1],[3,2]]
// Output: [0,1,2,3] or [0,2,1,3]
// Explanation: There are a total of 4 courses to take. To take course 3 you should have finished both     
//              courses 1 and 2. Both courses 1 and 2 should be taken after you finished course 0. 
//              So one correct course order is [0,1,2,3]. Another correct ordering is [0,2,1,3] .

class Solution {
public:
    
    unordered_map<int,int> v;
    unordered_map<int,int> recur;
    bool flag = 0;
    vector<int> st;
    

    
    void dfs(vector<int> edge[],unordered_map<int,int>& v,int curr){
        v[curr] = true;
        recur[curr] = true;
        for(auto i:edge[curr]){
            // checking if cycle exists or not
            if(recur[i]) flag = 1;
            if(!v[i]){
                dfs(edge,v,i);
            }
        }
        
        st.push_back(curr);
        recur[curr] = false;
    }
    
    vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
        vector<int> edge[n];
        
        // making the graph from prerequisites
        
        for(auto i:prerequisites){
            edge[i[1]].push_back(i[0]);
        }
        
        for(int i=0;i<n;i++){
            // if there is a cycle then no order is possible.
            if(flag) return {};
            if(!v[i]){
                dfs(edge,v,i);
            }
        }
        
        reverse(st.begin(),st.end());
        return st;
    }
};