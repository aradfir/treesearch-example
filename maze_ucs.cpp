#include <iostream>
#include <queue>
using namespace std;

typedef pair<int,int> location;
typedef vector<location> path;
typedef pair<int,path> pq_item;
// each point is difficulty (cost) of point
vector<vector<int>> maze ={
    {-1, -1, -1, -1, -1, -1, -1, -1, -1},
    {-1,  0,  5, 10,  0,  0,  0,  0, -1},
    {-1,  100,1,  5,  5,  0,  0,  0, -1},
    {-1,  1,  1,100,  6,  2,  2,  2, -1},
    {-1,  1,  1,  0,  0, 10, 10,  0, -1},
    {-1,  1,  1,  0,  0, 10, 10, -1, -1},
    {-1,  1,  1,  0,  0, 10, 10,  0, -1},
    {-1, -1, -1, -1, -1, -1, -1, -1, -1},
};
location goal{6,7};
bool is_in_path(path current_path, location node_to_check){
    for(location l:current_path){
        if(l == node_to_check)
            return true;
    }
    return false;
}

int get_maze_value(location l){
    return maze[l.first][l.second];
}


path ucs(location start,location end){

    // make a priority queue of paths, where the priority is the cost of the path (first item in pair)
    priority_queue<pq_item> Q;
    // create a starting path, with just the start location
    path root;
    root.push_back(start);
    // add the starting path to the queue, with cost 0
    Q.push({0,root});
    // until the queue is not empty...
    while(!Q.empty())
    {
        // ... take the item with the lowest cost (highest priority) ...
        pq_item node_to_expand = Q.top();
        // ... and remove it from the queue
        Q.pop();
        int current_cost = node_to_expand.first;
        path current_path = node_to_expand.second;
        location current_pos = current_path[current_path.size()-1];
        // if this path has reached the goal, then return it
        if( current_pos == goal)
        {
            return current_path;
        }
        
        // try to go right:
        location right_pos{current_pos.first, current_pos.second+1};
        
        // if right is not wall and not in path, then add it to path and add it to queue
        if(get_maze_value(right_pos) != -1 && !is_in_path(current_path,right_pos)){
            // copy current path and add right to it
            path new_path = current_path;
            new_path.push_back(right_pos);
            // add new path to queue, negate cost to make it a min heap
            Q.push({current_cost - get_maze_value(right_pos),new_path});
        }

        // try to go down:
        location down_pos{current_pos.first+1, current_pos.second};

        // if down is not wall and not in path, then add it to path and add it to queue
        if(get_maze_value(down_pos) != -1 && !is_in_path(current_path,down_pos)){
            path new_path = current_path;
            new_path.push_back(down_pos);
            // add new path to queue, negate cost to make it a min heap
            Q.push({current_cost - get_maze_value(down_pos),new_path});
        }
        // ... repeat for going left and up
        location left_pos{current_pos.first, current_pos.second-1};
        if(get_maze_value(left_pos) != -1 && !is_in_path(current_path,left_pos)){
            path new_path = current_path;
            new_path.push_back(left_pos);
            Q.push({current_cost - get_maze_value(left_pos),new_path});
        }
        location up_pos{current_pos.first-1, current_pos.second};
        if(get_maze_value(up_pos) != -1 && !is_in_path(current_path,up_pos)){
            path new_path = current_path;
            new_path.push_back(up_pos);
            Q.push({current_cost - get_maze_value(up_pos),new_path});
        }
    }
}

int main(){
    // call ucs with start and goal
    path p = ucs({1,1},goal);
    // print path
    for(location l:p){
        cout << "(" << l.first << "," << l.second << ")\t";
    }
    return 0;
}