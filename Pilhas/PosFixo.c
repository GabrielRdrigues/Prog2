#include <stdio.h>
#include <assert.h>
#include <string.h>
#define MAXSIZE 1024
int main(){
   float stack[MAXSIZE];
   int   n = 0; // INIT
   char  s[50];
   while(scanf(" %s", s) == 1){
       float x;
       if(sscanf(s, "%f", &x) == 1){
           assert(n < MAXSIZE);
           stack[n++] = x; // PUSH
       }else{
           for(int i = 0; i < strlen(s); i++){
               char c = s[i];
               assert(c == '+' || c == '-' || c == '*' || c == '/');
               printf("n=%d",n);
               assert(n>=2);
               float b = stack[--n]; // TOP E POP
               float a = stack[--n]; // TOP E POP
               stack[n++] /*PUSH*/ = (c == '+')? a+b:  (c == '-')? a-b:   (c == '*')? a*b:  a/b;
           }
       }
   }
   if(n > 0)
       printf("Resultado: %g\n", stack[n-1]);
}
