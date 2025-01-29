class Solution {
    int find(vector<int>&disJoinSet, int vertices){
        if ( disJoinSet[vertices] == -1 ){
            return vertices;
        }
        return disJoinSet[vertices] = find(disJoinSet,disJoinSet[vertices]);
    }
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int>disJoinSet(n+1,-1);
        for (auto edge:edges){
            int parent_x = find(disJoinSet,edge[0]);
            int parent_y = find(disJoinSet,edge[1]);

            if (parent_x == parent_y){
                return edge;
            }else{
                disJoinSet[parent_x] = parent_y;
            }
        }
        return {0,0};
    }
};
