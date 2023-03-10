#include<iostream>  
using namespace std;  
int num;  
int *x;  
int sum;  

void display(int num){
    for(int i=1;i<=num;i++){
        for(int j=1;j<=num;j++){
            if(x[i] == j){
                cout<<" @ ";
            }else{
                cout<<" * ";
            }
        }
        cout<<endl;
    }
}

bool place(int k)  
{  
    for(int j = 1;j<k;j++)  //对前几行遍历
        if(abs(x[k] - x[j]) == abs(k-j)||x[j] == x[k]) //如果当前行和之前行的皇后在同一对角线上或者在同一列上，就返回错误
            return false;  
        return true;  
  
}  
void backtrack(int t)  
{  
    if(t>num) //num为皇后的数目,即所有行都没出错
    {  
        sum++;//sum为所有的可行的解  
        for(int m = 1;m<=num;m++)  
        {  
            cout<<"<"<<m<<","<<x[m]<<">";//这一行用输出当递归到叶节点的时候，一个可行解  
        }  
        cout<<endl;  
        // display(num);
    }  
    else  
        for(int i = 1;i<=num;i++)  
        {  
            x[t] = i;  //t为行，i为列
            if(place(t))   
                backtrack(t+1);//此处的place函数用来进行我们上面所说的条件的判断，如果成立，进入下一级递归  ,t为行数
        }  
}  
int main()  
{  
    num = 8;  
    sum = 0;  
    x = new int[num+1];  
    for(int i= 0;i<=num;i++)  
        x[i] = 0;  
    backtrack(1);  
    cout<<"方案共有"<<sum<<endl;  
    delete []x;  
    return 0;
  
      
} 