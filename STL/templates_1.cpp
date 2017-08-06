#include <iostream>
using namespace std;

template <typename T>
T square(T x) {
    return x*x;
}

template <typename T>
class myVector
{
    T arr[50];
    int size;
public:
    myVector():size(0){}
    ~myVector(){}
    void push(T x) {
        arr[size++] = x;
    }
    void print() {
        for(int i = 0; i< size; i++)
            cout << arr[i] <<" ";
    }
    T get(int i) const{
        return arr[i];
    }
    T getSize() const {
        return size;
    }
};

template <typename T>
myVector<T> operator*(const myVector& first, const myVector& second) {
    myVector<T> newVector;
    for(int i = 0; i < first.getSize(); i++) {
        newVector.push(first.get()*second.get());
    }
    return newVector;
}

int main() {
    cout << square(5) << endl;
    cout << square<double>(5.2) <<endl; //Explicit type declaration not necessary

    myVector<int> V; //Explicit type declaration is compulsary
    V.push(2);V.push(5);V.push(7);V.push(12);V.push(36);
    V.print();

    cout << "Squared vector V: "<<endl;
    V = square(V);
    V.print();

    return 0;
}
