def main():
    N = int(input())
    A = [i-1 for i in map(int, input().split())]
    B = list(map(int, input().split()))
    C = list(map(int, input().split()))
    ans = 0
    for idx, a in enumerate(A):
        ans += B[a]
        if idx != 0 and A[idx-1] + 1 == A[idx]:
            ans += C[A[idx-1]]
    print(ans)


if __name__ == '__main__':
    main()
