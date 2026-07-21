import sys

def solve():
    N = int(input())
    if N % 2 == 1: print(0)
    else: 
        ans = 0
        for i in range(18):
            ans += N // pow(10, i+1)
            fd = 5 * pow(10, i+1)
            while fd <= N:
                ans  += (N // fd + 1) // 2
                fd *= 5
        print(ans)
    
    return 0

if __name__ == "__main__":
    solve()
