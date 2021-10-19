#include<stdio.h>
void main()
{
	printf("Enter the number of numbers ");
	scanf("%d",&n);
	lb=0;
	ub=n-1;
	printf("Enter Array\n");
	for(i=0;i<n;i++)
	scanf("%d",a[i]);
	quicksort(a,lb,ub); 
}
void quicksort(a,lb,ub)
{
	int j;
	if(lb>ub)
		j=partition(a,lb,ub);
	quicksort(a,lb,j+1);
	quicksort(a,j-1,ub);
}
int partition(int a[], int lb, int ub)
{
	int up,down,i;
	pivot=a[lb];
	up=ub;
	down=lb;
while (down<up) 
{
	while(a[down]<=pivot&&down<up)
	{
		down++;
	}                   
	while (a[up]=>pivot)
	{
		up--;
	} 
	if(down>up)
	{
		temp=a[down];
		a[down]=pivot;
		a[up]=temp;
	}
	a[lb]=a[up];
	a[up]=pivot;
	for(i=0;i<n;i++)
		printf("%d",a[i]);
	return up;
}
}
