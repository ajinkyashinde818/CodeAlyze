import sys
def input(): return sys.stdin.readline().strip()

def resolve():
    from itertools import accumulate

    N = int(input())  # len(A)
    A = list(map(int, input().split()))

    B = [0] + A
    B = list(accumulate(B))  # 累積和を格納したリスト作成

    ans=10**18
    for i in range(1, N):
        snuke=B[i]
        araiguma=B[N]-B[i]
        ans=min(ans,abs(snuke-araiguma))
    print(ans)
resolve()
