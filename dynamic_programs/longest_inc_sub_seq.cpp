//https://www.youtube.com/watch?v=Ns4LCeeOFS4&index=5&list=PLqM7alHXFySGbXhWx7sBJEwY2DnhDjmxm
#include <iostream>
#include <stdlib.h>
using namespace std;

int lis(int arr[], int n) {
    int max=0;
    int* lis = (int*)malloc(sizeof(int)*n);

    for(int i=0; i<n; i++)
        lis[i] = 1;

    for(int i=1; i<n; i++) {
        for(int j=0; j < i; j++) {
            if(arr[i]>arr[j] && lis[i] < lis[j]+1)
                lis[i]=lis[j]+1;
        }
    }

    for(int i=0; i<n; i++)
        if(max<=lis[i])
            max = lis[i];

    return max;
}

int main()
{
    int n;
    cout << "Enter the size of the array\n";
    cin >> n;

    int *arr = (int*)malloc(sizeof(int)*n);

    cout<<"Enter " << n << " elements: ";
    for(int i=0; i<n; i++)
        cin>>arr[i];

    int max = lis(arr,n);
    cout << "The length of the longest increasing subsequence is: " << max << endl;
    return 0;
}
