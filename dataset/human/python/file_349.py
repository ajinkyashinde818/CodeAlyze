import sys
read = sys.stdin.buffer.read
readline = sys.stdin.buffer.readline
readlines = sys.stdin.buffer.readlines
sys.setrecursionlimit(10 ** 8)
INF = float('inf')
MOD = 10 ** 9 + 7

def main():
    N = int(readline())
    A = list(map(int, readline().split()))
    B = list(map(abs, A))
    minus = 0
    for i in range(N):
        if A[i]<0:
            minus += 1
    if minus%2==0:
        ans = sum(B)
    else:
        ans = sum(B) - min(B)*2
    print(ans)
if __name__ == '__main__':
    main()
