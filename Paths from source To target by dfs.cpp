// Given a directed, acyclic graph of N nodes.  Find all possible paths from node 0 to node N-1, and return them in any order.

// The graph is given as follows:  the nodes are 0, 1, ..., graph.length - 1.  graph[i] is a list of all nodes j for which the edge (i, j) exists.

// Example:
// Input: [[1,2], [3], [3], []] 
// Output: [[0,1,3],[0,2,3]] 
// Explanation: The graph looks like this:
// 0--->1
// |    |
// v    v
// 2--->3
// There are two paths: 0 -> 1 -> 3 and 0 -> 2 -> 3.



#define pb push_back

class Solution {
public:
    
    stack<int> st;
    map<int,bool> vs;
    vector<vector<int>> ans;
    
    void func(stack<int> st){
        vector<int> curr;
        while(!st.empty()){
            int cu = st.top();
            curr.pb(cu);
            st.pop();
        }
        reverse(curr.begin(),curr.end());
        ans.pb(curr);
    }
    
    void dfs(vector<vector<int>>& graph,map<int,bool>& vs,int curr,int n){
        vs[curr] = true;
        st.push(curr);
        if(curr==n){
            func(st);
        }
        for(auto i:graph[curr]){
            if(vs[i]==false){
                dfs(graph,vs,i,n);
            }
        }
        vs[curr] = false;
        st.pop();
    }
    
    
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        dfs(graph,vs,0,n-1);
        return ans;
    }
};