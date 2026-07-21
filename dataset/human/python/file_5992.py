def main():
    N = int(input())
    A = list(map(int,input().split()))
    B = list(map(int,input().split()))
    C = list(map(int,input().split()))

    happiness = 0
    for i in range(N-1):
        happiness += B[A[i]-1]
        if A[i+1] - A[i] == 1:
            happiness += C[A[i]-1]

    print(happiness+B[A[-1]-1])

if __name__ == "__main__":
    main()
