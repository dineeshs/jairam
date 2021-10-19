#include<stdio.h>
void mergesort(int, int, int);
void merge(int,int,int);
void main()
{
 	int i,n,a[20];
 	printf("enter the limit\n");
 	scanf("%d",&n);
 	for(i=0;i<n;i++)
	scanf("%d",a[i]);
	mergesort(a,0,n-1);
	printf("The Array after sorting\n");
	for(i=0;i<n;i++)
		printf("%d ",a[i]);
}
void mergesort(int a[], int first, int last)
{
	int mid;
	if(first==last) return;
	else
	{
		mid=(first+last)/2;
		mergesort(a,first,mid);
		mergesort(a,mid+1,last);
		merge(first,mid,last);
	}
}
void merge(int a[ ], int first, int mid, int end) 
{
	int p = first,q = mid+1;
	int A[end-first+1], k=0;
	for(int i = first;i <= end ;i++) 
	{
		if(p > mid)    
			A[ k++ ] = a[ q++] ;
		else if ( q > end)   
			A[ k++ ] = a[ p++ ];
		else if( A[ p ] < a[ q ]) 
			A[ k++ ] = a[ p++ ];
		else
			A[ k++ ] = a[ q++];
	}
	for (int p=0 ; p< k ;p ++) 
		a[ first++ ] = Arr[ p ] ;                          
}