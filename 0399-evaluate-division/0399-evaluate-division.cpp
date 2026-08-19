/*
 * Problem: 399. Evaluate Division
 * 
 * Intuition & Approach:
 * 1. The Currency Exchange: Treat every variable (like 'a', 'b') as a node in a graph.
 *    An equation 'a / b = 2.0' is a directed edge from 'a' to 'b' with a weight of 2.0.
 * 2. The Reverse Path: If 'a / b = 2.0', then mathematically 'b / a = 1.0 / 2.0'. 
 *    So, we add a reverse edge from 'b' to 'a' with a weight of (1.0 / value).
 * 3. The Path Math (DFS): To find 'x / z', we need to find a path from 'x' to 'z' in our graph.
 *    If the path is x -> y -> z, the answer is just the multiplication of the edge weights:
 *    (x / y) * (y / z) = (x / z).
 * 4. The Edge Cases: If either the start or end variable doesn't exist in our graph, return -1.0.
 *    If we can't find a path between them using DFS, also return -1.0.
 * 
 * Complexity:
 * - Time: O(Q * (V + E)) where Q is the number of queries, V is variables, and E is equations.
 * - Space: O(V + E) to store the graph in an unordered_map.
 */

class Solution {
public:
    // DFS Function
    double dfs(string current, string target, unordered_map<string, vector<pair<string, double>>>& graph, unordered_set<string>& visited, double currentProduct) {
        
        // Agar current node hi target hai, toh ab tak ka multiplied answer return kar do
        if (current == target) {
            return currentProduct;
        }
        
        // Current node ko visited mark kar do
        visited.insert(current);
        
        // Saare padosiyon (neighbors) ko check karo
        for (auto neighbor : graph[current]) {
            string nextNode = neighbor.first;
            double weight = neighbor.second;
            
            // Agar padosi visited nahi hai, toh DFS aage badhao
            if (visited.find(nextNode) == visited.end()) {
                
                // Agle raste par jao, naya product = (currentProduct * raste ka tax/weight)
                double result = dfs(nextNode, target, graph, visited, currentProduct * weight);
                
                // Agar aage se answer mil gaya (yani path exists), toh turant wahi result wapas bhejo
                if (result != -1.0) {
                    return result;
                }
            }
        }
        
        // Agar koi bhi rasta target tak nahi pahuncha
        return -1.0;
    }

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        // Step 1: Graph banayenge
        // Key: string (city), Value: vector of pairs {neighbor_city, path_weight}
        unordered_map<string, vector<pair<string, double>>> graph;
        
        for (int i = 0; i < equations.size(); i++) {
            string u = equations[i][0];
            string v = equations[i][1];
            double val = values[i];
            
            // Asli rasta: u -> v with weight 'val'
            graph[u].push_back({v, val});
            
            // Nakli/Reverse rasta: v -> u with weight '1.0 / val'
            graph[v].push_back({u, 1.0 / val});
        }
        
        // Step 2: Queries ko answer karenge
        vector<double> results;
        
        for (int i = 0; i < queries.size(); i++) {
            string start = queries[i][0];
            string end = queries[i][1];
            
            // Edge Case 1: Agar dono mein se koi ek bhi graph mein exist nahi karta
            if (graph.find(start) == graph.end() || graph.find(end) == graph.end()) {
                results.push_back(-1.0);
            } 
            // Edge Case 2: Agar start aur end same hain (e.g., a / a)
            else if (start == end) {
                results.push_back(1.0);
            } 
            // Step 3: DFS chala kar rasta dhundo
            else {
                unordered_set<string> visited; // Har query ke liye naya visited set chahiye
                double ans = dfs(start, end, graph, visited, 1.0); // Initial product is 1.0
                results.push_back(ans);
            }
        }
        
        return results;
    }
};