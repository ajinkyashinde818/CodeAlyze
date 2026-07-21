def main():
    N = int(input())
    A = [int(number) for number in input().split()]
    B = [int(number) for number in input().split()]
    C = [int(number) for number in input().split()]

    ans = sum(B)
    for i in range(N):
        if i > 0:
            if A[i-1]+1 == A[i]:
                ans += C[A[i-1]-1]
    print(ans)

if __name__ == '__main__':
    main()
