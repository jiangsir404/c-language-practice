/*二分查找算法
要求:
    1. 有序
    2. 顺序存储
*/

#include<stdio.h>
#include<stdlib.h>
int BinarySearch(int arr[],int key,int low,int high){
	int mid;
	while(low<=high){
		mid=(low+high)/2;
		if(key==arr[mid]){//不是key==mid
			return mid; //返回下标
		}
		else if(key<arr[mid]){
			high=mid-1;
		}
		else low=mid+1;
	}
	return 0;
}
int main(){
	int high,low,key,position;
	int array[]={0,1,2,3,4,5,6,7,8,9};
	printf("请输入key值:");
	scanf("%d",&key);
	if(position=BinarySearch(array,key,0,9)){
		printf("key的位置为:%d",position);
	}else
	{
		printf("error\n");
	}
	return 0;
}