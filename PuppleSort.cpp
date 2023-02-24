#include <stdio.h>
//定义顺序表的最大长度
#define MAXLENGTH 100;
//定义线性表的顺序存储结构
typedef struct{
    //定义线性表里存储的数据类型为整型
    int *R;
    //定义顺序表当前的长度
    int length;
}Sqlist;

void PuppleSort(Sqlist &l){
    //建立临时变量
    int temp;
    //建立标志位，用来标记这一趟是否需要比较，默认为false表示需要比较，true表示不需要比较
    bool flag = false;
    int count=0;
    for(int j=1;j<l.length && !(flag);j++){
        flag = true;//如果这一趟没有需要交换的，就把flag置为true
            for(int i=1;i<=l.length-j;i++){
                if(l.R[i] < l.R[i-1]){
                    flag = false;  //这一趟有需要交换，把flag置为false          
                    temp = l.R[i];
                    l.R[i] = l.R[i-1];
                    l.R[i-1] = temp;                                      
                }
                count+=1;  
            }            
    }
    printf("&&&&&%d\n",count);
}

int main(){
    int a[8];
    a[0] = 25;
    a[1] = 48;
    a[2] = 31;
    a[3] = 5;
    a[4] = 6;
    a[5] = 19;
    a[6] = 12;
    a[7] = 16;
    for(int i=0;i<8;i++){
        printf("%d\n",a[i]);
    }
    printf("************************************\n");
    Sqlist l;
    l.R=a;
    l.length=8;
    PuppleSort(l);
     for(int i=0;i<l.length;i++){
        printf("%d\n",a[i]);
    }
}