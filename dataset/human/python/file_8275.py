import sys
sys.setrecursionlimit(10000000)
MOD = 10 ** 9 + 7
INF = 10 ** 15

def main():
    N = int(input())
    A = list(map(int,input().split()))

    s = N*(N + 1)//2
    tot = sum(A)
    if tot%s == 0:
        cnt = tot//s
    else:
        print('NO')
        return
    
    A.append(A[0])
    x = 0
    for i in range(N):
        diff = A[i + 1] - A[i]
        if cnt - diff < 0:
            print('NO')
            return
        if (cnt - diff)%N == 0:
            x += (cnt - diff)//N
        else:
            print('NO')
            return
    print('YES' if x == cnt else 'NO')
if __name__ == '__main__':
    main()
