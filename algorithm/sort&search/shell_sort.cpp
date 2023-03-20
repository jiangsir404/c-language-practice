
#include<iostream>
#include<stdlib.h>
#include<stdio.h>
using namespace std;
int n=10;
void Shell_sort(int *array){
	int k=n/2;  //增量 
	while(k>0) 
	{
		int i,j;
		for(i=k+1;i<=n;i++)//因为array[0]为空，为此i是从k+1开始的,并i<=n 
		{
			if(array[i]<array[i-k]){//两个相邻间隔的比较，如果后一个小于前一个 
				array[0]=array[i];
				for(j=i-k;j>0&&array[0]<array[j];j-=k){//array[0]再和间隔i-k的元素j再比较 
					array[j+k]=array[j];//如果小，就把j往后挪一个间隔距离 
				}
				array[j+k]=array[0];
			}
		}
		k=k/2;
	}
}
int main(){
	int *array=(int*)malloc(sizeof(int)*(n+1));
    cout << "pls input 10 num:";
	for(int i=1;i<=n;i++)
	{
		cin>>array[i];
	}
	Shell_sort(array);
	for(int i=1;i<=n;i++){
		cout<<array[i]<<" ";
	}
	cout<<endl;
	return 0;
}