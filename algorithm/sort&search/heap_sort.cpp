		/**
 * 
 * @authors Your Name (you@example.org)
 * @date    2016-12-26 21:14:22
 * @version $Id$
 */
#include<iostream>
#include<stdio.h>
using namespace std;

void HeapAdjust(int a[],int low,int high)
{
	int max = a[low];
	int j;
	for(j = 2*low;j<=high;j*=2){//沿左孩子向下筛选
		if(j<high&&a[j]<a[j+1]) ++j; //如果左孩子小于右孩子，则j为右孩子的下标
		if(max>=a[j]) break;//如果顶点值大于节点值，就跳出循环，无需交换，已经是大顶堆
		a[low] = a[j];
		low = j; //找到最小节点该插入的位置
	}
	a[low] = max;

}

void HeapSort(int a[],int n)
{
	int i;
	for(i = n/2;i>0;--i) //将a[1..n] 建成大顶堆
		HeapAdjust(a,i,n);
	for(i=n;i>1;--i)
	{
		swap(a[1],a[i]);
		HeapAdjust(a,1,i-1); //将a[1..i-1]重新调整为大顶堆
	}
}

void swap(int &a,int &b)
{
	int tmp = a;
	a = b;
	b = tmp;
}
int main(){
	int a[6] = {0,1,2,5,3,4};
	HeapSort(a,6);
	for(int i=1;i<=5;i++)
	{
		cout<<a[i]<<" ";
	}
}