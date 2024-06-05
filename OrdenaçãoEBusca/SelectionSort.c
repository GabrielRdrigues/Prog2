#include <stdio.h>
#include <stdlib.h>

void selection_sort(int* v,int I0,int I1){
    //if(I0==I1)
        //return;

    int min = I0;
    for(int i=I0;i<=I1;i++){
        if(v[i]<v[min])
            min=i;
    }
    int temp=v[I0];
    v[I0]=v[min];
    v[min]=temp;
    if(I0!=I1)
        selection_sort(v,I0+1,I1);
    //else
        //return;
}

int main(){
    int* v = (int[]){10,5,2,50,1,24,70,1};
    selection_sort(v,0,7);
    for(int i=0;i<8;i++){
        printf(" %d\n",v[i]);
    }
}