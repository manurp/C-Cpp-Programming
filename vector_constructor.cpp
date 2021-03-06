// constructing vectors
#include <iostream>
#include <vector>
using namespace std;

int main ()
{
  // constructors used in the same order as described above:
  vector<int> first;                                // empty vector of ints
  vector<int> second (4,100);                       // four ints with value 100
  vector<int> third (second.begin(),second.end());  // iterating through second
  vector<int> fourth (third);                       // a copy of third
    //cout<<*second.begin()<<endl;
  // the iterator constructor can also be used to construct from arrays:
  int myints[] = {16,2,77,29};
  vector<int> fifth (myints, myints + sizeof(myints) / sizeof(int) );

  cout << "The contents of fifth are:";
  for (vector<int>::iterator it = fifth.begin(); it != fifth.end(); ++it)
    cout << ' ' << *it;
  cout << '\n';
cout << "The contents of second are:";
  for (vector<int>::iterator it = second.begin(); it != second.end(); ++it)
    cout << ' ' << *it;
  cout << '\n';
  return 0;
}
