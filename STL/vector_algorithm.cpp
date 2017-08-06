#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> v;
    v.push_back(0);v.push_back(15);v.push_back(-11);
    v.push_back(2);v.push_back(5);v.push_back(1);
    vector<int>::iterator itr1 = v.begin();
    vector<int>::iterator itr2 = v.end();

    for(std::vector<int>::iterator itr = itr1; itr != itr2; itr++)
        cout << *itr <<" ";

    sort(itr1, itr2);

    cout << endl;
    for(std::vector<int>::iterator itr = itr1; itr != itr2; itr++)
        cout << *itr <<" ";
    return 0;
}
