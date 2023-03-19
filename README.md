## c语言练习代码
记录自己用于c语言学习的一个项目，包括一些c语言基础知识的demo.和
题库的练习，算法的练习。

### 资料和书籍学习
- 《c和指针》
- 《c语言编程经典例题100》
- 《c陷阱与缺陷》
- 《剑指offer》
- 《编程之美》
- [菜鸟编程 C 语言经典100例](https://www.runoob.com/cprogramming/c-100-examples.html)
- [菜鸟编程 C 语言实例](https://www.runoob.com/cprogramming/c-examples.html)

## 文章笔记
- [ ] 经典排序算法一
- [ ] 经典排序算法二

### 代码
- [x] basic 基础操作
- [x] point 指针操作
- [x] struct 结构体操作
- [x] array 数组操作
- [x] file 文件操作
- [x] module常用库函数
    - 数学计算math.h
    - 字符库函数 ctype.h
    - 字符串函数 string.h
    - 系统库函数 stdlib.h
    - 输入输出库函数 stdio.h
- [x] DataStructure 数据结构
    - 八皇后问题
    - 哈夫曼编码问题
    - 线性表链式结构
    - 线性表顺序结构
    - [ ] 栈
    - [ ] 队列
    - [ ] 二叉树
- [x] algorithm常见c语言算法
    - 闰年判断
    - 求素数
    - 求完数
    - 求水仙花数
    - 求最大公因数和最小公倍数
    - 猴子吃桃问题
    - 自由落球问题
    - 报数退圈问题
    - 杨辉三角问题
    - strcat函数实现
    - strcpy函数实现
    - strcmp函数实现  
    - 矩阵乘法算法实现
    - 矩阵转置算法实现  
    - 递归程序
        - 求斐波那契数列
        - 求阶乘
    - 排序算法

- [x] code_practice c语言经典编程100中的练习(精选出30道题)
- [ ] leetcode c语言编程题练习


demo: lession14.c 

```
/*
题目：求一个3*3矩阵主副对角线元素之和
1 2 3
4 5 6
7 8 9
思路：利用双重for循环控制输入二维数组，主对角线元素为i=j,副对角线元素为i+j=N-1
*/

#include<stdio.h>
#define N 3

int main(){
    int a[N][N]={0};
    int i,j,sum;
    for(i=0;i<N;i++){
        for(j=0;j<N;j++){
            scanf("%d", &a[i][j]);
            //主对角线和副对角线的值
            if(i==j || i+j==N-1){
                sum += a[i][j];
            }
        }
    }
    printf("sum: %d", sum);
    return 0;
}

```