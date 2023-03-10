//判断闰年的算法
// 非整百年4年一润，如2004,2008。
//整百年400年一润，又称世纪闰年，如2000为闰年，但1900，2100都不是闰年。

#include<stdio.h>

int is_leapyear(int year){
    if (year % 4 == 0 && year % 100 !=0) return 1;
    if (year % 400 == 0 && year % 100 == 0) return 1;
    return 0;
}

int main(){
    int i;
    printf("1980-2030 leapyear: ");
    for(i=1980;i<2030;i++){
        if(is_leapyear(i)){
            printf("%d ", i);
        }
    }
    printf("\n1900,2000,2100:");
    printf("%s ", is_leapyear(1900)?"True":"False");
    printf("%s ", is_leapyear(2000)?"True":"False");
    printf("%s ", is_leapyear(2100)?"True":"False");
}


