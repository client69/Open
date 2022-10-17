#include<stdio.h>
#include<math.h>
main()
{
	float a,b;
	printf("Enter any two Floating point numbers:");
	scanf("%f%f",&a,&b);
	printf("\nAdition=%f",(a+b));
	printf("\nSubtraction=%f",(a-b));
	printf("\nMultiplication=%f",(a*b));
	printf("\nDivision=%f",(a/b));
	printf("\nModulo Division=%f",fmod(a,b));
}
