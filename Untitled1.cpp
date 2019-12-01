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

	printf("请输入要比较元素个数：");
	scanf("%d",&n);
    
	printf("\n");
	printf("按升序输入原始元素：\n");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);

     printf("\n");
	printf("请输入要查找的元素：");
	scanf("%d",&k);


    printf("\n");
	l=binarysearch(a,n,k);
	printf("查找元素的下标为：%d\n",l);
}
