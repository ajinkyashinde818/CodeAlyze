import sys
sys.setrecursionlimit(10000000)
MOD = 10 ** 9 + 7
INF = 10 ** 15

def main():
    A,B,C,N = map(int,input().split())
    ans = 0
    for i in range(N + 1):
        if i*A > N:
            break
        a = i*A
        for j in range(N + 1):
            if j*B + a > N:
                break
            b = j*B
            if (N - a - b)%C == 0:
                ans += 1
    print(ans)
if __name__ == '__main__':
    main()
