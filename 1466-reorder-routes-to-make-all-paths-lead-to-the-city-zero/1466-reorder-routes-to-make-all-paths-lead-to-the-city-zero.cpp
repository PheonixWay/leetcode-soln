/*
 * Problem: 1466. Reorder Routes to Make All Paths Lead to the City Zero
 * 
 * Intuition & Approach:
 * 1. The Capital City: We want all roads to point TOWARDS City 0. 
 * 2. The Inspector: Imagine we start at City 0 and travel OUTWARDS to visit all cities.
 *    Since we are walking away from City 0, we want the actual one-way roads to point 
 *    in the opposite direction of our travel.
 * 3. The Trick (Fake 2-Way Roads): Because some one-way roads point the wrong way, 
 *    we might not even be able to reach every city using normal DFS. So, we pretend 
 *    the graph is undirected (2-way).
 * 4. The Weight System: 
 *    - For an original road A -> B, we store it as adj[A].push_back({B, 1}). The '1' means 
 *      "if we travel this way, we are following the original arrow pointing away from 0. FLIP IT."
 *    - We also add a fake reverse road adj[B].push_back({A, 0}). The '0' means "if we travel 
 *      this way, the original arrow actually points towards 0. DO NOT FLIP."
 * 5. DFS: Start from 0, visit all nodes, and simply sum up the weights of the roads we take.
 * 
 * Complexity:
 * - Time: O(N) where N is the number of cities. We visit every city exactly once.
 * - Space: O(N) for the adjacency list storing pairs and the visited array.
 */

class Solution {
public:
    int flipCount = 0;

    void dfs(int currentCity, vector<vector<pair<int, int>>>& adj, vector<bool>& visited) {
       visited[currentCity] = true;

       for (auto neighbor : adj[currentCity]) {
            int nextCity = neighbor.first;
            int needsFlip = neighbor.second;

            if (visited[nextCity] == false) {
            
                flipCount += needsFlip;
            
                dfs(nextCity, adj, visited);
            }
        }
    
    }

    int minReorder(int n, vector<vector<int>>& connections) {
       
       vector<vector<pair<int,int>>> adj(n);
       vector<bool> visited(n, false);

       for(int i=0;i<connections.size();i++){
        int u=connections[i][0];
        int v=connections[i][1];

        adj[u].push_back({v , 1});
        adj[v].push_back({u , 0});

       }

       dfs(0, adj, visited);

       return flipCount;
    }
};