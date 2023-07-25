#include <stdio.h>
#include <math.h>
#include <conio.h>
int main()
{
    int i,j,count,temp,num[25];
    printf("Enter number of elements: ");
    scanf("%d",&count);
    printf("Enter %d number: ", count);
    for(i=0;i<count;i++);
    scanf("%d",&num[i]);
    for(i=1;i<count;i++);
    {
        temp=num[i];
        j=i-1;
        while ((temp<num[j])&&(j>=0))
        {
            num[j+1]=num[j];
            j=j-1;
        }
      scanf("%d",&count);
      printf("Enter %d number: ");
      for(i=0;i<count;i++);
      scanf("%d",&num[i]);
      for(i=1;i<count;i++);
     {
        temp=num[i];
        j=i-1;
        while ((temp<num[j])&&(j>=0))
        {
            num[j+1]=num[j];
            j=j-1;
        }
        num[j+1]=temp;
     }  
        printf("Order of sorted element:");
        for(i=0;i<count;i++);
        printf("%d",num[i]);
        getch();
        return 0;

        
    }

    
}