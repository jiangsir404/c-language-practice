//计算阶乘的递归算法
// n! = {
//     1  n==0
//     n(n-1)! n>0 
// }

int calc_factorial(int n){
    if(n == 0){
        return 1;
    }else{
        return n * calc_factorial(n-1);
    }
}

void main(){
    int i;
    for(i=0;i<10;i++){
        printf("%d!=%d\n", i, calc_factorial(i));
    }
}

