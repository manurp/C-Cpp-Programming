#include <vector>
#include <iostream>
#include <iterator>
#include <algorithm>
using namespace std;


/*int main() {
    vector<int> v;
    int n,k;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> k;
        v.push_back(k);
    }
    sort(v.begin(),v.end());

    for(int it:v) {  //Works in c++11 not in earlier versions
        cout << it <<" ";
    }
    return 0;
}
*/
int main() {
    vector<int> v;
    int n;
    cin >> n;

    //copy_n(istream_iterator<int>(cin), n, back_insert_iterator<vector<int>>(v));
    copy_n(istream_iterator<int>(cin), n, back_inserter<vector<int>>(v));
    sort(v.begin(), v.end());
    copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));

    return 0;
}
