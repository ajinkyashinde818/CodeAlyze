import sys
from bisect import bisect_left
def input(): return sys.stdin.readline().strip()


def main():
    N = int(input())
    A = list(map(int, input().split()))
    A.sort()
    
    """
    もし負の数が偶数個存在すればそれらはすべて正の数にできる。
    もし負の数が奇数個存在すればそれは最終的に１個にできる。
    """

    idx = bisect_left(A, 0)
    if idx % 2 == 0:
        print(sum(A[idx:]) - sum(A[:idx]))
    elif idx < len(A) :
        cand1 = sum(A[idx:]) - sum(A[:idx]) + A[idx - 1] * 2
        cand2 = sum(A[idx:]) - sum(A[:idx]) - A[idx] * 2
        print(max(cand1, cand2))
    else:
        print(-sum(A) + A[-1] * 2)
    


if __name__ == "__main__":
    main()
