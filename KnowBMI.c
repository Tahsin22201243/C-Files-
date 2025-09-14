#include<stdio.h>
int main()
{
    int a,b,c;
    printf("Enter three person BMI: ");
    scanf("%d %d %d",&a,&b,&c);
    if(a>=b && a>=c)
        printf("%d is in health risk",a);
    else if(b>=a && b>=c)
        printf("%d is in health risk",b);
    else
        printf("%d is in health risk22",c);  
    return 0;
}