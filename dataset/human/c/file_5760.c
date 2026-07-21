#include<stdio.h>
#define max(x, y) ((x) > (y) ? (x) : (y))
#define min(x, y) ((x) < (y) ? (x) : (y))
main()
{
    long int size, maxer, miner, temp;
    fscanf(stdin, "%ld", &size);
    fscanf(stdin, "%ld", &miner);
    fscanf(stdin, "%ld", &temp);
    maxer = temp - miner;
    miner = min(miner, temp);
    size -= 2;
    while(size--){
        fscanf(stdin, "%ld", &temp);
        maxer = max(maxer, temp - miner);
        miner = min(miner, temp);
    }
    printf("%ld\n", maxer);
}
