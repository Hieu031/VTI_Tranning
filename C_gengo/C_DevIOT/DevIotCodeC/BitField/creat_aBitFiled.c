#include <stdio.h>
#include <string.h>

struct
{
  unsigned int tuoi : 3;
} Tuoi;

int main( )
{
   Tuoi.tuoi = 3;
   printf( "Bo nho bi chiem giu boi Tuoi la Sizeof( Tuoi ) =  %d\n", sizeof(Tuoi) );
   printf( "Tuoi.tuoi : %d\n", Tuoi.tuoi );

   Tuoi.tuoi = 6;
   printf( "Tuoi.tuoi : %d\n", Tuoi.tuoi );

   Tuoi.tuoi = 7;
   printf( "Tuoi.tuoi : %d\n", Tuoi.tuoi );
   
   /* Bay gio chung ta thu in nhieu hon 3 bit */
   printf( "\n-----------------------\n");
   Tuoi.tuoi = 8;
   printf( "Tuoi.tuoi : %d\n", Tuoi.tuoi );
   Tuoi.tuoi = 9;
   printf( "Tuoi.tuoi : %d\n", Tuoi.tuoi );
   
   printf("\n===========================\n");
   printf("QTM chuc cac ban hoc tot! \n");

   return 0;
}