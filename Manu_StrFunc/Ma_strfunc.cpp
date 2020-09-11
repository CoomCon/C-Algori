#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <assert.h>

using namespace std;

/* 
 strlen()函数
功能：计算给定字符串的（unsigned int型）长度，不包括'\0'在内
 */
int strlen_m(const char* str)
{
    if(sizeof(str) == 0)
        return 0;
    int len = 0;
    while(*str++!='\0')
    {
        len++;
    }
    return len;
}
/*
strcpy()函数

功能:字符串复制函数,strcpy把含有'\0'结束符的字符串复制到另一个地址空间，返回值的类型为char*。
*/

char* strcpy_m(const char * str)
{
    
    if(*str=='\0')
    {
        return NULL;
    }
    char *res  = (char*)malloc(strlen(str) * sizeof(char));
    char *r = res;
    while(*str!='\0')
    {
        *res++ = *str++;
    }
    return r;
}
/*

strcmp()函数

功能:字符串比较函数
str1==str2 返回0
str1>str2 返回1
str1<str2 返回-1

*/
int strcmp_m(const char* s1,const char* s2)
{
    assert((s1 != NULL) && (s2 != NULL));
    
    while (*s1 == *s2) {
        if (*s1 == '\0')
            return 0;
        
        ++s1;
        ++s2;
    }
    
    return *s1 - *s2;
}
/*
* strstr()函数 
* 功能:strstr(str1,str2) 函数用于判断字符串str2是否是str1的子串
* 如果是，则该函数返回str2在str1中首次出现的地址；否则，返回NULL。
*/


/**
 * 
 * 
 * strcat()函数
 * 功能:把src所指向的字符串（包括“\0”）复制到dest所指向的字符串后面（删除*dest原来末尾的“\0”）
 * 要保证*dest足够长，以容纳被复制进来的*src。*src中原有的字符不变。返回指向dest的指针。
 * 
 * strcmp()函数
 * 功能:对两个字符串进行比较,若s1、s2字符串相等，
 * 则返回零；若s1大于s2，则返回正数;否则，则返回负数。
 * 
 * memcpy()函数
 * 功能::将str指向地址为起始地址的连续n个字节的数据
 * 复制到以dest指向地址为起始地址的空间内,函数返回一个指向dest的指针.
 */

int finds(vector<int> dum,int t)
{
    int i=dum.size()/2;
    while(dum[i]!=t)
    {
        if(dum[i]>t)
            i = i / 2;
        else
            i = (i + dum.size()) / 2;
    }
    return i;
}

int findd(vector<int> &dum,int s,int e,int t)
{
    int temp = (s + e) / 2;
    if(dum[temp] == t)
        return temp;
    else if(dum[temp] > t)
    {
        return findd(dum, s, temp, t);
    }else
    {
        return findd(dum, temp, e, t);
    }
}

int main()
{
    vector<int> dum = {1, 2, 3, 4, 5, 6, 77, 88};
    char nd1 = 0x11;
    char nd2 = 0x22;
    char nd3 = 0x33;
    char nd4 = 0x44;
    int inin = 0x11223344;
    char nind = ((char*)&inin)[0];
    char mind = ((char*)&inin)[1];
    char kind = ((char*)&inin)[2];
    char lind = ((char*)&inin)[3];    
    
    int t = 5;
    if(dum.size()==0)
        return 0;
    int ans = finds(dum, t);
    int ans2 = findd(dum, 0, dum.size(),t);
    const char *a = "da";
    int srl = strlen(a);
    int srl2 = strlen_m(a);
    char * an = strcpy_m(a);

    const char *strcmp1 = "abcdef";
    const char *strcmp2 = "abcdefh";
    int strcmp3 = strcmp_m(strcmp1, strcmp2);
    return 0;
}