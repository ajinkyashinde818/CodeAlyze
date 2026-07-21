import sys
readline = sys.stdin.buffer.readline
sys.setrecursionlimit(10 ** 8)
INF = float('inf')
MOD = 10 ** 9 + 7

def main():
    N = int(readline())
    if N%2==1:
        print(0)
    else:
        ans = 0
        for i in range(1,100):
            ans += N//((5**i)*2)
        print(ans)
if __name__ == '__main__':
    main()
