#include<stdio.h>
int i;
void printarray(int a[],int n)
{
	printf("Pass\n");
	for(i=0;i<n;i++)
		printf("\t %d",a[i]);
	printf("\n");
}
void heapify(int a[],int n,int i)
{
	int temp,pos,left,right;
	pos=i;
	left=((2*i)+1);
	right=((2*i)+2);
	if(left<n && a[left]>a[pos])
		pos=left;
	if(right<n && a[right]>a[pos])
		pos=right;
	if(pos!=i)
	{
		temp=a[i];
		a[i]=a[pos];
		a[pos]=temp;
	}
		printarray(a,n);
	heapify(a,n,pos);
 }
}
void heapsort(int a[],int n)
{
	int temp;
	for(i=((n/2)-1);i>=0;i--)
		heapify(a,n,i);
	for(i=n-1;i>=0;i--)
	{
		temp=a[0];
		a[0]=a[i];
		a[i]=temp;
		heapify(a,i,0);
	}
}
int main()
{
	int n,a[20];
	printf("Enter the no.of elements");
	scanf("%d",&n);
	printf("\n Enter the array");
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	heapsort(a,n);
	printf ("\nThe sorted array\n");
	for(i=0;i<n;i++)
	printf("\n %d",a[i]);
}

