#include<stdio.h>
void main()
{
	int t,i,n,a[20],j;
	printf("Enter size:");
	scanf("%d",&n);
	printf("\nEnter the elements:");
	scanf("%d",&a[0]);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	for(i=0;i<n;i++)
	{
		j=i;
		while(j>0&&a[j-1]>a[j])
		{
			t=a[j-1];
			a[j-1]=a[j];
			a[j]=t;
			j--;
		}
	}
	printf("\nArray after sorting:");
	for(i=0;i<n;i++)
		printf("%d ",a[i]);
	printf("\n");
}

 
