#include<stdio.h>
#include<math.h>
int main()
{
	int a=10,b=20;
	printf("\n after Addition a is %d",(a+=b));
	printf("\n after Substarction a is %d",(a-=b));
	printf("\n after Multiplicationtion a is %d",(a*=b));
	printf("\n after Division a is %d",(a/=b));
    printf("\n after ModuloDivision a is %d",(a%=b));
}

