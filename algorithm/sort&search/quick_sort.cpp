#include<iostream>
#include<stdlib.h>
#include<stdio.h>
using namespace std;
int n;
int Partition(int *array,int low,int high) 
{
	int pivotkey=array[low];//用字表的第一个记录作为枢轴记录 
	array[0]=array[low];
	while(low<high)//从表的两端交替地向中间扫描 
	{
		while(low<high&&array[high]>=pivotkey)
		{
			high--;
		}
		array[low]=array[high];//将比枢轴记录小的记录移到低端，但下标不会变 
		while(low<high&&array[low]<=pivotkey)
		{
			low++;
		}
		array[high]=array[low];//将比枢轴记录大的记录移动高端 
	}
	array[low]=array[0];//枢轴记录到位 
	return low;//返回枢轴位置 
}

void QuickSort(int *array,int low,int high)
{
	if(low<high)
	{
		int pivotloc=Partition(array,low,high);//将数组一分为二 
		QuickSort(array,low,pivotloc-1);//对低字表递归排序 
		QuickSort(array,pivotloc+1,high);//对高子表递归排序 
	}
}
int main(){
	int i;
	int array[6]={0,1,5,4,2,3};
	for(i=1;i<=5;i++)
	{
		printf("%d ",array[i]);
	}
	printf("\n");
	QuickSort(array,1,5);
	for(i=1;i<=5;i++)
	{
		printf("%d ",array[i]);
	}
	printf("\n");
	return 0;
}
