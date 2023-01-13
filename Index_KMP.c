#include <stdio.h>

 int* getNext(char *p, int length, int next[]){ //求模式串p的next函数值并存入数组next
    int i,j;
    i=0;
    next[0]=-1;
    j=-1;
    while(i<length){
        if(j==-1||p[i]==p[j]){
            ++i;
            ++j;
            next[i]=j;
        }else{
            j=next[j];
        }
    }
    return next;

}

int Index_KMP(char *s, char *p, int tlength, int plength, int pos, int next[]){
    //利用模式串p的next函数，求p在主串s中从第pos个字符开始的位置
    //若匹配成功，返回模式串在主串中的位置(下标)，否则返回-1
    int i,j;
    i = pos -1;
    j = -1;
    while(i<tlength && j<plength){
        if(j==-1 || s[i]==p[j]){
            i++;
            j++;
        }else{
            j=next[j];
        }
    }
    if(j>=plength) return i-plength;
    else return -1;

}

int main(){
    char s[16]={'a','b','a','c','b','c','a','b','a','b','a','b','b','c','b','c'};
    char t[7]={'a','b','a','b','a','b','b'};
    int slength=sizeof(s)/sizeof(s[0]);
    int tlength=sizeof(t)/sizeof(t[0]);
    int next[tlength];
    int* nextarray = getNext(t,tlength,next);
    int result = -1;
    result = Index_KMP(s,t,slength,tlength,0,nextarray);
    printf("result:%d\n",result);

}
