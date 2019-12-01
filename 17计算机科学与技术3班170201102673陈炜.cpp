#include<stdio.h>
#define N 1024
int binarysearch(int *a,int n,int k)
{
	int low=0,high=n,i=0,mid;

	while(low<=high&&i==0)
	{
		mid=(int)((low+high)/2);
		if(k==a[mid]) 
			i=mid;

		else if(k>a[mid])
			low=mid+1;
		else high=mid-1;
	}

	return i;
}
void main()
{
	int n,i,a[N],k,l;

	printf("Please enter the number of elements to compare:");
	scanf("%d",&n);
    
	printf("\n");
	printf("Enter original elements in ascending order:\n");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);

     printf("\n");
	printf("Please enter the element to find:");
	scanf("%d",&k);


    printf("\n");
	l=binarysearch(a,n,k);
	printf("The subscript of the lookup element is:%d\n",l);
}
