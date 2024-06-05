#include <stdio.h>
#include <limits.h>

//-------------------------------------------------
/*int main(){ // Aritmética modular
  unsigned int x = UINT_MAX;
  x++;
  printf("%u\n", x);


   printf("%lu\n",  sizeof(short)     );
   printf("%lu\n",  sizeof(int)       );
   printf("%lu\n",  sizeof(long)      );
   printf("%lu\n",  sizeof(long long) );


}*/
//----------------------------------------------

/*int main(){
   unsigned int y = 2147483647U + 1; // Se não colocar o U terá overflow de INT
   printf("%u\n",y);
   long x = 31243257L*252365536;
   printf("%ld\n", x);
}*/

// --------------------------------------------------

int main(){
    int u=31243257;
    int v=252365536;
    long x= (long)u*v;
    printf("%ld",x);
}



