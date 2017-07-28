#include <stdio.h>

int main() {
    int a[2][3];
    int (*pa)[3] = a;
    int* ppa = pa;
    **pa = 1;  //a[0][0]
    *(*(pa+1))=2; //a[1][0];
    //**pa = 1;
    //**pa+1 = 2;
    printf("%d\n",pa );
    printf("%d\n",&a[0][0]);
    printf("%d\n",**pa );
    printf("%d\n",&a[0]);
    printf("%d\n",ppa);

    printf("\n%d\n",*pa );
    printf("\n%d\n",ppa);

    *(ppa+1)=5;  //a[0][1]
    //printf("%d\n",)
    printf("%d\n",a[0][0]);
    printf("%d\n",a[0][1]);
    printf("%d\n",a[1][0]);
   return 0;
}
