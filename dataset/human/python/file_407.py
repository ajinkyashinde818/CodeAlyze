def main():
    n = int(input())
    A = list(map(int, input().split()))
    B = [None] * n
    cnt = 0
    for i in range(n):
        if A[i] <= 0:
            cnt += 1
        B[i] = abs(A[i])
    print(sum(B) - 2 * min(B) if cnt % 2 == 1 else sum(B))


if __name__ == '__main__':
    main()
