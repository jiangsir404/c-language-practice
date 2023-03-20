/*
八进制转二进制: 先将八进制转出十进制，再将十进制转二进制
*/

#include<stdio.h>
#include<math.h>

void oct_to_bin(){
    int bin_num=0,dec_num=0,i=0,oct_num;
    scanf("%d", &oct_num);
    //八进制转十进制
    while(oct_num){
        dec_num += (oct_num%10)*pow(8,i++);
        oct_num = oct_num/10;
    }
    //十进制转二进制
    i=1;
    while(dec_num){
        bin_num += (dec_num%2)*i;
        dec_num /= 2;
        i *= 10;
    }
    printf("output bin_num:%d, dec_num:%d", bin_num,dec_num);

}

int main(){
    oct_to_bin();
    return 0;
}