#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void strInit(char str[]);//str[]を0で初期化
void extIntStr(char str[],int data[]);//str[]から数値(int)を抽出しdata[]に順次格納
void incsort(int data[],int len);//data[]を昇順ソート
void decsort(int data[],int len);//data[]を降順ソート
void printIntArray(int data[],int len);//data[]をprint
int* inputArray(int n);//文字列を受け取り数値を抽出、n個の数値(int)を格納した配列のポインタをreturn
int* cpyArray(int data[],int len);//配列(int)を複製した配列のポインタをreturn

//don't forget free(data);

int main(){
    int n;
    int *a,*b,*c;
    scanf("%d ",&n);
    a=inputArray(n);
    b=inputArray(n);
    c=inputArray(n-1);
    int ans=0;
    for(int i=0;i<n;i++){
        ans += b[a[i]-1];
        if(a[i]+1==a[i+1])ans += c[a[i]-1];
    }
    free(a);
    free(b);
    free(c);
    printf("%d",ans);
    return 0;
}

//temp##############################################

void strInit(char str[]){
    int len=strlen(str);
    for(int i=0;i<len;i++){
        str[i]=0;
    }
}

void extIntStr(char str[],int data[]){
    int length=strlen(str);
    str[length-1]=' ';
    char buff[12];
    int j,index;
    index=j=0;
    for(int i=0;i<length;i++){
        if(str[i]!=' '){
            buff[j++]=str[i];
        }else{
            data[index++]=atoi(buff);
            strInit(buff);
            j=0;
        }
    }
}

void incsort(int data[],int len){
    for(int i=0;i<len-1;i++){
        for(int j=i+1;j<len;j++){
            if(data[i]>data[j]){
                int tmp=data[i];
                data[i]=data[j];
                data[j]=tmp;
            }
        }
    }
}

void decsort(int data[],int len){
    for(int i=0;i<len-1;i++){
        for(int j=i+1;j<len;j++){
            if(data[i]<data[j]){
                int tmp=data[i];
                data[i]=data[j];
                data[j]=tmp;
            }
        }
    }
}

void printIntArray(int data[],int len){
    for(int i=0;i<len;i++){
        printf("%d\n",data[i]);
    }
}

int* inputArray(int n){
    int *data;
    data=(int*)malloc(sizeof(int)*n);
    char *get;
    get=(char*)malloc(sizeof(char)*11*n+1);
    fgets(get,11*n+1,stdin);
    extIntStr(get,data);
    free(get);
    return data;
}

int* cpyArray(int data[],int len){
    int *cp;
    cp=(int*)malloc(sizeof(int)*len);
    for(int i=0;i<len;i++){
        cp[i]=data[i];
    }
    return cp;
}

//temp##############################################
