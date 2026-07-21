/*
  第4回ユニリタプログラミングコンテスト～練習サイト～
  C言語用
  ファイル名 qA.c
  作成者 228 金子幸裕 2017/06/14 18:00
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

int main( void )
{
    int nc;

    scanf( "%d" , &nc );

    if ( nc < 1200 )
    {
        printf("ABC");
    }
    else
    {
        printf("ARC");
    }


    printf("\n");

    return ( 0 );

}
