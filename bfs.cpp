#include <iostream>
#include <vector>
#include <queue>
using namespace std;


//adjacency_matrix (2d array that shows which graph nodes are connected)
vector<vector<int>> adj_matrix{
{0,1,1,0,1,0,0},
{1,0,1,0,1,0,0},
{1,1,0,1,0,0,0},
{0,0,1,0,0,1,0},
{1,1,0,0,0,1,0},
{0,0,0,1,1,0,1},
{0,0,0,0,0,1,0},
};


// this function is similar to is_in_visited in dfs
// checks if node_to_check already exists in path, so we dont get into a loop when searching
bool is_in_path(vector<int> path, int node_to_check){
    for(auto node:path){
        if(node == node_to_check)
            return true;
    }
    return false;
}

// function takes in where we are at the start (origin), where we are trying to go (destination)
// returns what cities (nodes) we need to go to to reach destination
vector<int> bfs(int origin,int destination){
    // queue of tree elements we want to expand
    queue<vector<int>> Q;
    // we need to start a path with our starting position
    // we use a vector of integers to show a path, just like nodes in "visited" in dfs
    // the last item in vector is where our agent is currently in (while planning)
    vector<int> root;
    root.push_back(origin);
    Q.push(root);

    // until either all nodes are expanded (no path found) or a path is found, run this loop:
    while(!Q.empty()){
        // take the first element from the front of the queue, and delete it from the queue
        auto path = Q.front();
        Q.pop();
        // find the position of the planner in this path
        int current_position = path[path.size() - 1];
        // if we are in the destination, return the path as our answer!
        if(current_position == destination)
            return path;
        // adj_matrix[current_position] shows what nodes are connected to current_position
        // if adj_matrix[current_position][i] is 0, current_poisition and i are not connected, else they are connected
        for(int i = 0; i < adj_matrix[current_position].size(); i++){
            //if connected, and we havent been in this node before, add to the end of current path and put back to queue
            if(adj_matrix[current_position][i] != 0 && !is_in_path(path,i))
            {
                //copy old path
                vector<int> new_path = path;
                //add new node to end
                new_path.push_back(i);
                //add back to queue
                Q.push(new_path);
            }
        }
        
    }
    return {};
}
int main(){
    // call bfs function from city 0 to city 6 (as we saw in class)
    // expected answer was 0 -> 4 -> 5 -> 6
    auto path_to_six = bfs(0,6);
    cout<<"Path to six:"<<endl;
    for(auto node:path_to_six){
        cout<<node<<"\t";
    }
    cout<<endl;
    return 0;
}