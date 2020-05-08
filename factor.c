#include "types.h"
#include "user.h"


unsigned long 
convert(char* str)
{
    unsigned long mult = 1;
    int i;
    unsigned long re = 0;
    int len = strlen(str); 
    for(i = len -1 ; i >= 0 ; i--)
    {
        // We are subtracting 48 because the numbers in ASCII starts at 48.
        re = re + ((int)str[i] -48)*mult;  //why multiple by 1?
        mult = mult*10; //why multiple by 10?
    }
    return re;
}

int
main (int argc, char * argv [])
{
  int number = convert(argv[1]) ,div=2;

   while(number!=0){
        if(number%div!=0)
            div = div + 1;
        else {
            number = number / div;
            printf(1,"%d ",div);
            if(number==1)
                break;
        }
    }
  printf(2,"\n");
  exit();
}
