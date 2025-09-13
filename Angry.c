#include<stdio.h>
int main()
{
    int a,b,c;
    scanf("%d %d %d",&a,&b,&c);
    if(a>b && a>c)
    {
        printf("This is the Red Angry bird");
    }
    else if(b>c)
    {
        printf("This is the Black bird");

    }
    else 
    printf("This the bird I want the most ");
    return 0;

}