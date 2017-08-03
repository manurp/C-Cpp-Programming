#include <iostream>
#include <map>
using namespace std;

int main() {
    map<int, string> mp;
    mp[1] = "manu";
    mp[2] = "rohit";
    mp[3] = "lekhan";
    mp.insert(pair<int, string>(4,"prajwal"));
    mp.insert(make_pair(5,"sathya"));
    for(map<int, string>::iterator it = mp.begin(); it != mp.end(); it++) {
        cout<< it->first<<" -> "<<it->second<<endl;
    }

    return 0;
}
