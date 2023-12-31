#include <iostream>
#include <queue>
#include <vector>

using namespace std;
typedef vector<int> path;
typedef pair<int,path> pq_item;


int main(){
    // hazine ha manfi she (priority queue max-heap hast) 
    priority_queue<pq_item> Q1;
    // agar min-heap mikhastim:
    // priority_queue<pq_item,vector<pq_item>,greater<pq_item>> Q2;

    // add test items to pq
    // ezafe kardane item ha be safe olaviat
    Q1.push({-80,{0,1}});
    Q1.push({-100,{0,2}});
    Q1.push({-1000,{0,3}});

    // top = maximum value
    // chon manfi kardim, gharinash kamtarine
    pq_item best_item = Q1.top();
    // hazine node i ke baiad baz she ro minevisim + masire feli
    cout<<"TOTAL COST:"<<-best_item.first<<"\t\tPath:";
    for(int val:best_item.second){
        cout<<val<<"\t";
    }

    return 0;
}