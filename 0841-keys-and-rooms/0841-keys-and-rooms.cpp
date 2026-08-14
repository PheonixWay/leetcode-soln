class Solution {
public:
    void dfs(int currentRoom, vector<vector<int>>& rooms, vector<bool>& visited) {
        visited[currentRoom] = true;

        
        for (int nextRoomKey : rooms[currentRoom]) {
            if (!visited[nextRoomKey]) {
                dfs(nextRoomKey, rooms, visited);
            }
        }
    }

    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool> visited(n, false);

        dfs(0, rooms, visited);

       
        for (int i = 0; i < n; i++) {
            if (visited[i] == false) {
                return false;
            }
        }

        return true;
    }
};