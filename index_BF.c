#include <stdio.h>


int Index(char *c, char *s,  int clen, int slen, int pos)
    /*查找并返回模式串s在主串c中从pos开始的位置（下标)，若s不是c的子串，返回-1*/
    /*模式串s和主串c第一个字符的下标为0*/
    {
        int i,j;  //i,j分别用于指出主串字符和模式串字符的位置
        i = pos;
        j=0;

        while(i<clen && j < slen){
            if(c[i] == s[j]){
                i++;
                j++;
            }else{
                i=i-j+1;
                j=0;
            }
    }/*while*/
    if(j>= slen) return (i - slen);
    return -1;
}

int main()
{
    //定义主串
    char mainArray[10]={'s','d','f','e','t','p','q','z','k','r'};
    //定义一个子串
    char subArray[3]={'z','k','r'};
    int pos=0;
    int mainlength = sizeof(mainArray)/sizeof(mainArray[0]);
    int sublength = sizeof(subArray)/sizeof(subArray[0]);
    int result = Index(mainArray,subArray,mainlength,sublength,pos);
    printf("final:%d\n",result);
}
