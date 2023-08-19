#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 1 1 1 1 1 1 1 1 1
// 1 0 0 1 0 0 1 0 1
// 1 0 1 0 0 0 0 1 1
// 1 0 0 0 1 0 1 1 1
// 1 1 1 1 0 0 0 0 1
// 1 0 0 0 0 0 0 0 1
// 1 1 1 0 1 0 0 0 1
// 1 1 1 1 1 1 1 1 1
vector<vector<int>> maze ={
    {1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 1, 0, 0, 1, 0, 1},
    {1, 0, 1, 0, 0, 0, 0, 1, 1},
    {1, 0, 0, 0, 1, 0, 1, 1, 1},
    {1, 1, 1, 1, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 1, 1, 0, 1, 0, 0, 0, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1},
};

bool is_in_visited(vector<pair<int,int>> visited,pair<int,int> new_pos){
    for(int i=0 ; i < visited.size();i++)
    {
        auto position = visited[i];
    }
    for (auto position : visited)
    {
        if(position == new_pos){
            return true;
        }
    }
    return false;
}
void dfs(vector<pair<int,int>> visited, pair<int,int> current_pos){
    // go right if possible:
    pair<int,int> new_pos{current_pos.first,current_pos.second+1};
    if(maze[new_pos.first][new_pos.second] == 0 && !is_in_visited(visited,new_pos))
    {
        auto visited_new = visited;
        visited_new.push_back(new_pos);
        cout<<"Going to <"<<new_pos.first<<","<<new_pos.second<<">!"<<endl;
        dfs(visited_new,new_pos);
    }
}
int main(){

    for (int i = 0; i < maze.size(); i++)
    {
        for (int j = 0; j < maze[i].size(); j++)
        {
            cout<<maze[i][j]<<" ";
        }
        cout<<endl;
    }
    dfs({},{1,1});

    return 0;
}