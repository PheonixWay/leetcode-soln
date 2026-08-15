/*
 * Problem: 547. Number of Provinces
 * 
 * Intuition: 
 * This is a classic "Count Connected Components" graph problem. 
 * The given matrix represents cities and their connections. A province is simply 
 * an isolated group of directly or indirectly connected cities.
 * 
 * Approach:
 * 1. Create a 'visited' array (size N, default false) to track explored cities.
 * 2. Scan through every city using a for-loop (0 to N-1).
 * 3. If a city is NOT visited (visited[i] == false):
 *    - It means we found a new, uncounted Province. Increment 'provinces'.
 *    - Trigger DFS from this city.
 * 4. The DFS traverses the matrix to find all connected friends and marks them 
 *    as 'visited = true'. This prevents the main loop from counting them again.
 * 
 * Complexity:
 * - Time: O(N^2) because we must check every cell in the N x N adjacency matrix.
 * - Space: O(N) for the visited array and DFS recursion call stack.
 */


class Solution {
public:

    void dfs(vector<vector<int>>& isConnected,vector<bool>& visited,int currentCity){
        visited[currentCity]=true;

        for(int i=0;i<isConnected.size();i++){
            if(isConnected[currentCity][i]== 1 && visited[i]==false){
                dfs(isConnected,visited,i);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<bool> visited(n,false);
        int provinces=0;
        for(int i=0;i<n;i++){
            if(visited[i]==false){
                provinces++;

                dfs(isConnected,visited,i);
            }
        }

        return provinces;
        
    }
};



