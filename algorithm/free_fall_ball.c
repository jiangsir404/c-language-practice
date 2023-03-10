/*题目：一球从 100 米高度自由落下，每次落地后反跳回原高度的一半；
再落下，求它在第 10 次落地时，共经过多少米？第 10 次反弹多高？
*/

#include<stdio.h>
void main(){
    float sn=100,hn=sn/2;
    int n;
    for(n=2;n<=10;n++){
        sn = sn+2*hn;
        hn = hn/2;
    }
    printf("the total of road is %f\n", sn);
    printf("the tenth of %f meter\n", hn);
}