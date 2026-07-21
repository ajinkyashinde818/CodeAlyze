import sys
sys.setrecursionlimit(10**6)

root = list()


def dfs(A, num, N, memo):
    if memo[A[num]-1] == 1:
        return root.index(A[num])
    else:
        root.append(A[num])
        memo[A[num]-1] = 1
        return dfs(A, A[num]-1, N, memo)


def main():
    N, K = map(int, input().split())
    A = list(map(int, input().split()))

    memo = [0] * N
    start = dfs(A, 0, N, memo)

    if K <= len(root):
        print(root[K-1])
    else:
        index = (K - start) % (len(root)-start)
        loop = root[start:]
        print(loop[index-1])


if __name__ == "__main__":
    main()
