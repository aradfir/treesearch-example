#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<int> example{1,2,3,4,5};
    auto element = example[2];

    for(int i = 0; i < 5; i++){
        int item = example[i];
        cout<<item<<"\t";
    }
    cout<<endl;
    for(int aaaaaa:example){
        cout<<aaaaaa<<"\t";
    }
    cout<<endl;
    for(auto item:example){
        cout<<item<<"\t";
    }
    cout<<endl;

    return 0;
}