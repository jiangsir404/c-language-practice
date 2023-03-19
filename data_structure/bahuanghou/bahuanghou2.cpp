#include <iostream>
using namespace std;
#define Queue_num 8
int ans=0; //解数
int top=-1;//栈顶指针
int data[Queue_num]; //存储皇后位置

//入栈
void Push(int x)
{
    top++; 
    data[top]=x;
}
//出栈
void Pop()
{
    top--;                                                 
}

void display()  //将栈的数组形式打印成棋盘形式
{
    cout<<"NO."<<ans<<":"<<endl;                                    
    for(int i=0;i<Queue_num;i++)
    {
        for(int j=0;j<data[i];j++)
            cout<<"- "; //不放置处打印“-”
        cout<<"Q";  //放置处打印“Q”
        for(int j=Queue_num-1;j>data[i];j--)
            cout<<" -";
        cout<<endl; 
    }
    cout<<endl;
}


void SetStack(){top=-1;}      


bool place()
{
    for(int i=0;i<top;i++) 
        if(data[top]==data[i]||(abs(data[top]-data[i]))==(top-i))  //判断是否在同一列同一斜线
            return false;                                          
    return true;
}

/*放N皇后的递归函数*/
void PlaceQueen(int row)
{
    for (int col=0;col<Queue_num;col++) //穷尽0~7，即穷尽列
    {
        Push(col);
        if (place())//判断摆放皇后的位置是否安全
        {
            if (row<Queue_num-1) //若还没有放到第八个皇后，则进行下一个皇后的放置
                PlaceQueen(row+1);                                    
            else
            {
                ans++;     
                for(int m = 0;m<Queue_num;m++)  
                    {  
                        cout<<"<"<<m+1<<","<<data[m]+1<<">";//这一行用输出当递归到叶节点的时候，一个可行解  
                    }  
                cout<<endl; 
                display();   
            }
        }
        Pop(); //若不符合条件则出栈,即回溯  
    }
}


int main()
{
    PlaceQueen(0);//从栈底开始赋值
    cout<<"the total number of solutions is:"<<ans<<endl; //输出摆放方法的总数
    return 0;
}