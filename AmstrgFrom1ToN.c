#include <stdio.h>
#include <math.h>
int main()
{
    int num,ld,count,sum,i,n;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        sum = 0;
        num = i;
        while (n != 0)
	    { 
       	 	n = n / 10; 
        	count=count++; 
    	} 
        
        while(num > 0)
        {
            ld = num % 10;
            sum = sum + pow(ld, count);
            num = num / 10;
        }
        if(i == sum)
        {
            printf("%d ", i);
        }

    }

    return 0;
}
