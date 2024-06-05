#include <stdio.h>
#include <stdlib.h>

int main(){
    int a[5] = {10, 15, 23, 90, 25};
    printf("%p\n", &a[0]);
    printf("%p\n", a);
    printf("%d\n",*(a+1));
}
