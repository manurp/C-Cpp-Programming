#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> v;
    v.push_back(5);
    v.push_back(9);
    v.push_back(7);
    v.push_back(3);
    v.push_back(2);

    for(unsigned int i=0; i<v.size();i++) {
        cout<<v[i] <<" ";
    }

    cout<<endl<< "Size = "<<v.size() <<endl;
    v.clear();
    cout<<"Size after clearing = "<<v.size()<<endl;
    v.push_back(4);
    v.push_back(10);

    for(unsigned int i=0; i<v.size();i++) {
        cout<<v.at(i) <<" ";
    }
    return 0;
}
