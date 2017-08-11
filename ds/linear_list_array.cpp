#include <iostream>
#include <algorithm>
#include <sstream>
#include <string>
#include "myExceptions.h"
using namespace std;

template <class T>
class linearList {
public:
    virtual ~linearList() {}
    virtual bool empty() const = 0; //returns true iff list is empty
    virtual int size() const = 0; //return number of elements in list
    //virtual T& get(int theIndex) const = 0; //return element whose index is theIndex
    //virtual int indexOf(const T& theElement) const = 0; // return index of first occurence of theElement
   // virtual void erase(int theIndex) = 0; // remove the element whose index is theIndex
    //virtual void insert(int theIndex, const T& theElement) = 0; // insert theElement so that its index is theIndex
    //virtual void output(ostream& out) const = 0; // insert list into stream out
};

template <class T>
void changeLength1D(T*& a, int oldLength, int newLength) {
    if (newLength < 0)
        throw illegalParameterValue("new length must be >= 0");
    T* temp = new T[newLength];
    int number = min(oldLength, newLength);
    copy (a, a + number, temp);
    delete [] a;
    a = temp;
}

template <class T>
class arrayList : public linearList<T> {
public:
    // Constructor, copy constructor and destructor
    arrayList(int initialCapacity = 10);
    arrayList(const arrayList<T>&);
    ~arrayList() {delete [] element;}

    //ADT methods
    bool empty() const {return listSize == 0;}
    int size() const {return listSize;}
    //T& get(int theIndex) const;
    //int indexOf(const T& theElement) const;
    //void erase(int theIndex);
    //void insert(int theIndex, const T& theElement);
    //void output(ostream& out) const;

    //additional method
    int capacity() const {return arrayLength;}

protected:
    void checkIndex(int theIndex) const; // throw illegalIndex if theIndex is invalid
    T* element;  // 1D array to hold list elements
    int arrayLength;
    int listSize;
};

template <class T>
arrayList<T>::arrayList(int initialCapacity) { // ctor
    if (initialCapacity < 1) {
        ostringstream s;
        s << "Initial capacity = " << initialCapacity << "Must be > 0";
        throw illegalParameterValue(s.str());
    }
    arrayLength = initialCapacity;
    element = new T[arrayLength];
    listSize = 0;
}

template <class T>
arrayList<T>::arrayList(const arrayList<T>& theList) {  // cctor
    arrayLength = theList.arrayLength;
    listSize = theList.listSize;
    element = new T[arrayLength];
    copy(theList.element, theList.element + listSize, element);
}

int main() {
    arrayList<int> a(20);
    return 0;
}
