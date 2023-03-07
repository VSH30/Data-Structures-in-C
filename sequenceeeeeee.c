#include<stdio.h>
#include<conio.h>
// To calculate power
float power(float base, float pow)
{
     if (pow==1)
        return base;
     else
         return base*power(base, pow-1); // recursion function
}
// To create factorial
float fact(float num)
{
     if (num==0)
        return 1;
     else
         return num*fact(num-1);  // recursion function
}
void main()
{
     int n;
     float sum=0,x,i;
     printf("Enter the value of X: ");
     scanf("%f",&x);
     printf("\nEnter the value of n: ");
     scanf("%d",&n);
     for(i=1;i<=n;i++)
     {
          sum=sum+(power(x,i)/fact(i));
     }
     printf("Sum of series is: %f",sum);
}
