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