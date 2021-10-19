#include<stdio.h>
void main()
{
	int i,j,n,a[20],temp;
	printf("Enter the array size:");
	scanf("%d",&n);
	printf("\nEnter the Array elements:-");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	for(i=0;i<n;i++)
		for(j=0;j<(n-i)-1;j++)
			if(a[j]>a[j+1])
			{
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
	printf("\nArray after sorting:");
	for(i=0;i<n;i++)
	printf("%d ",a[i]);
	printf("\n");
}
