/*
i/p: num1=101010
     num2=110101
     base=2
o/p: 1011111

i/p: num1=123
     num2=12
     base=4
o/p: 201
*/
// Method 1

#include <stdio.h>

int main()
{
    int num1,num2,base,sum,carry=0,res=0,t1,t2,place=1;
    scanf("%d%d%d",&num1,&num2,&base);
    while(num1!=0 || num2!=0)
    {
        t1=num1%10;
        t2=num2%10;
        sum=(t1+t2)+carry;
        res=res+((sum%base)*place);
        
        num1=num1/10;
        num2=num2/10;
        carry=sum/base;
        place*=10;
    }

    printf("%d",carry*place+res); 
}

// Method 2
#include <stdio.h>

int main()
{
    int num1,num2,base,sum,carry=0,res=0,t1,t2,place=1;
    scanf("%d%d%d",&num1,&num2,&base);
    while((num1/place) || (num2/place))
    {
      
        sum=(((num1/place)%10)+((num2/place)%10))+carry;
        res=res+((sum%base)*place);
        carry=sum/base;
        place*=10;
    }

    printf("%d",carry*place+res); 
}

