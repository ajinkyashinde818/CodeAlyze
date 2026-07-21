#include <stdio.h>
#include <string.h>

void swap(int *x, int *y){
    int c;
    c=*x;
    *x=*y;
    *y=c;
}

void Newton(int data[10][5], int H, int c)
{
    int i,j;
    for(i=0;i<H-1;i++)
    {
        for(j=0;j<H-1;j++)
        {
            if(data[j+1][c] == 0)
            {   // small -> large
                swap(&data[j][c], &data[j+1][c]);
            }
        }
    }
}

void print(int data[10][5], int H)
{
    int i, j;

    for(i = 0;i < H;++i)
    {
        for(j = 0;j < 5;++j)
        {
            printf("%d", data[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int main()
{
    int H;
    int i, j, k;
    int disk[10][5], pt;
    int flag, flag1, l, r;

    while(scanf("%d", &H) == 1 && H)
    {
        memset(disk, -1, sizeof(disk));
        pt = 0;

        for(i = 0;i < H;++i)
        {
            for(j = 0;j < 5;++j)
            {
                scanf("%d", &disk[i][j]);
            }
        }

        while(1)
        {
            flag = 1;

            for(i = 0;i < H;++i) // 行ごとに連続の検出
            {
                l = 0;
                r = 0;
                flag1 = 0;

                for(j = 0;j < 4;++j)
                {
                    if(disk[i][j] == 0)
                    {
                        l = j + 1;
                        r = j + 1;
                    }
                    else if(disk[i][j] == disk[i][j+1] && !flag1)
                    {
                        r = j + 1;
                    }
                    else if(disk[i][j] != disk[i][j+1])
                    {
                        if(r - l > 1)
                        {
                            flag1 = 1;
                        }
                        else{
                            l = j + 1;
                            r = j + 1;
                        }
                    }
                }

                if(r - l > 1)
                {
                    for(k = l;k <= r;++k)
                    {
                        pt += disk[i][k];
                        disk[i][k] = 0;
                    }

                    flag = 0;
                }

//                print(disk, H);

            }

            for(j = 0;j < 5;++j) // ニュートンを呼んで盤面を整理する
            {
                Newton(disk, H, j);
            }

//            print(disk, H);

            if(flag)
            {
                printf("%d\n", pt);
                break;
            }
        }
    }

    return 0;
}
