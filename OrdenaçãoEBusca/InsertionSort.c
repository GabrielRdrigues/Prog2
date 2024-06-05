#include <stdio.h>

void insertion_sort(int* v,int n){
    for(int i=1;i<n;i++){
        int x=v[i];
        for(int j=i;j>0;j--){
            if(v[j-1]>v[j]){
                v[j]=v[j-1];
                v[j-1]=x;
            }
            else
                break;
        }
    }
}

int main(){
    int* v=(int[]){6,5,3,1,8,7,2,4};
    insertion_sort(v,8);
    for(int i=0;i<8;i++){
        printf("%d ",v[i]);
    }
}