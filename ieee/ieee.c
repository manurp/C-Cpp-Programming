#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

struct ip_adrr {
    char s[33];
};

struct ip_adrr ip[10];

void swap_ip(int a,int b){
    char temp[33];
    strcpy(temp,ip[a].s);
    strcpy(ip[a].s, ip[b].s);
    strcpy(ip[b].s, temp);
}

int get_num(char *str, int count) {
    int i = 0;
    int j = 0, num=0;

    int k = 10;

    while(1){
        if(i==count)
            break;
        if(str[j]=='.' || str[j] == '-')
            i++;
        j++;
    }

    while(str[j] != '.' && str[j] != '-') {
        num = num*k + (str[j] - 0x30);
        j++;
    }
    return num;
}

int isgreat(char str1[], char str2[]) {
    int i;
    for(i=0;i<8;i++){
        if(get_num(str1,i)>get_num(str2,i))
            return 1;
    }
    return 0;
}

void sort_ip(int q) {
    int i,j;

    for(i=0;i<q-1;i++) {
        for(j=0;j<q-i-1;j++) {
           if(isgreat(ip[j].s, ip[j+1].s))
            swap_ip(j,j+1);
        }
    }
}

int main() {

    char str[33] = "225.124.16";
    int x;
    //x = get_num(str,0);
    //printf("x");
    int i;
    for(i=0;i<7;i++){
        gets(str);
        strcpy(ip[i].s,str);
    }
    sort_ip(2);
    for (i = 0; i < 7; ++i)
    {
        puts(ip[i].s);
    }
    return 0;
}
