#include <stdio.h>

int a[] = {1,2,4,5,8,9,12,47,59};
int x; //value to be searched in the array

int bin_search(int low, int high) {
    if(low > high) {
        return -1;
    }
    int mid;
    mid = (low + high)/2;
    return a[mid] == x ? mid : a[mid] > x ? bin_search(low, mid-1) : bin_search(mid+1, high);
}

int main() {
    printf("Enter the value to searched: ");
    scanf("%d",&x);
    int res_ind = bin_search(0, 8);
    if(res_ind == -1)
        printf("\n%d not found\n",x );
    else
        printf("\n%d found at index %d\n",x, res_ind);
    return 0;
}
