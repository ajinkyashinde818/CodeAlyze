def main():
    N = int(input())
    A = [int(i) - 1 for i in input().split()]
    B = [int(i) for i in input().split()]
    C = [int(i) for i in input().split()]
    satisfaction_degrees = 0
    for i in range(N):
        satisfaction_degrees += B[A[i]]
        if i != 0:
            if A[i] == A[i-1] + 1:
                satisfaction_degrees += C[A[i] - 1]
    print(satisfaction_degrees)

if __name__ == "__main__":
    main()
