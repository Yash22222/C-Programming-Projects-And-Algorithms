/*Yash Ashok Shirsath*/
/*0/1 Knapsack Problem using Dynamic Programming Approach*/

#include<stdio.h>

void kp(int n,int pro[],int wt[],int m);
int max(int a,int b);

void main()
{
	int i,j,n;
	int wt[20], pro[20];
	int m;

	printf("Enter no. of weights:");
	scanf("%d",&n);
	printf("Enter the capacity:");
	scanf("%d",&m);

	printf("Enter the weights\n");
	for(i=1;i<=n;i++)
	{
		printf("\nWT %d:",i);
		scanf("%d",&wt[i]);
	}

	printf("Enter the profit\n");
	for(i=1;i<=n;i++)
	{
		printf("\npro %d:",i);
		scanf("%d",&pro[i]);
	}
	kp(n,pro,wt,m);
}

int max(int a,int b)
{
	return((a>b)?a:b);
}


void kp(int n,int pro[],int wt[],int m)
{
	int x[20],v[20][20],i,j;
	for(i=1;i<=n;i++)
	{
		x[i]=0;
	}
	for(i=0;i<=n;i++)
	{
		v[i][0]=0;
	}
	for(i=0;i<=m;i++)
	{
		v[0][i]=0;
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			if(wt[i]>j)
			{
				v[i][j]=v[i-1][j];
			}
			else
			{
				v[i][j]=max(v[i-1][j],pro[i]+v[i-1][j-wt[i]]);
			}
		}
	}

	printf("Output:\n");

	for(i=0;i<=n;i++)
	{
		for(j=0;j<=m;j++)
		{
		printf("%d ",v[i][j]);
	}
	printf("\n");
	}


	printf("THE PROFIT IS:%d",v[n][m]);
	printf("\n");
	i=n;
	j=m;
	while(i!=0)
	{
		if(v[i][j]!=v[i-1][j])
		{
			x[i]=1;
			j=j-wt[i];
		}
	i=i-1;
	}
	for(i=1;i<=n;i++)
	printf("%d ",x[i]);
}
