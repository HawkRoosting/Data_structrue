//这儿的下标默认是1开始
#include<iostream>
 
using namespace std;
 
#define MAXLEN 255
 
typedef struct{
    char ch[MAXLEN];
    int length;
}SString;
 
typedef struct {
    char *ch;
    int length;
}HString;
 
//初始化串
void InitSting(HString &S);
//赋值操作，把串T复制为chars
bool StrAssign(HString &T,HString chars);
//复制操作，由串S复制到T
bool StrCopy(HString &T,HString S);
//判空，是返回true，否则false
bool StrEmpty(HString S);
//若s>t 返回>0  s=t 返回=0  s<t 返回<0
int StrCompare(HString S,HString T);
//返回串长
int StrLength(HString S);
//求字串，用sub返回串s的第pos个位置开始的长度为len的串
bool SubString(HString &Sub,HString S,HString pos,HString len);
//字符串拼接，用T返回由S1和S2连接的新串
bool Concat(HString &T,HString S1,HString S2);
//返回串T在S中第一次出现的位置，不存在返回0
int Index(HString S,HString T);
//清空操作
bool ClearString(HString &S);
//销毁串
bool DestoryString(HString &S);
 
 
void InitSting(HString &S){
    S.ch = (char *)malloc(MAXLEN*sizeof(char));
    S.length = 0;
}
 
bool StrAssign(HString &T,char* chars){  //T接收传过来的目标分配字符串
    T.length = 0;
    for(int i=1;chars[i];i++){
        T.ch[i] = chars[i];            //?指针与数组
        T.length++;
    }
    return true;
}
 
bool StrCopy(HString &T,HString S){
    T = S;
    return true;
}
 
bool StrEmpty(HString S){
    if(S.length == 0) return true;
    return false;
}
 
int StrCompare(HString S,HString T){
    int i=1;
    while(i<S.length&&i<T.length){
        if(S.ch[i]!=T.ch[i]) return S.ch[i]-T.ch[i];
        i++;
    }
    return S.length-T.length;
}
 
int StrLength(HString S){
    return S.length;
}
 
bool SubString(HString &Sub,HString S,int pos,int len){
    if(pos+len-1>S.length) return false;
    for(int i=1;i<=len;i++){
        Sub.ch[i] = S.ch[pos+i-1];
    }
    Sub.ch[len+1] = '\0';
//    cout<<Sub.ch+1<<endl;
    Sub.length=len;
 
    return true;
}
 
bool Concat(HString &T,HString S1,HString S2){
    for(int i=1;i<=S1.length;i++){
        T.ch[i] = S1.ch[i];
    }
    for(int i=1;i<=S2.length;i++){
        T.ch[i+S1.length] = S2.ch[i];
    }
    T.length = S1.length+S2.length;
    return true;
}
 
int Index(HString S,HString T){
    int i=1,n=StrLength(S),m=StrLength(T);
    HString sub;
    InitSting(sub);
    while(i<n-m+1){
        SubString(sub,S,i,m);
//        cout<<sub.ch+1<<endl;
        if(StrCompare(T,sub)!=0) i++;
        else return i;
    }
    return 0;
}
 
bool ClearString(HString &S){
    S.length = 0;
    return true;
}
//销毁串
bool DestoryString(HString &S){
    free(S.ch);
    S.length = 0;
}
 
void test(){
 
    HString s,t;
    InitSting(s);
    InitSting(t);
    char *sr = " asbdfd";
    char *tr = " 345";
    StrAssign(s,sr);
    StrAssign(t,tr);
    printf("%d\n",Index(s,t));
}
 
int main(){
 
    test();
    return 0;
}