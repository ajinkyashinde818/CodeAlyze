def main():

    N = int(input())
    A = [i for i in map(int, input().split())]
    B = [i for i in map(int, input().split())]
    C = [i for i in map(int, input().split())]
    satisf = 0
    for i in range(N):
        satisf += B[A[i] - 1]
    for i in range(N - 1):
        if A[i + 1] == A[i] + 1:
            satisf += C[A[i] - 1]
    print(satisf)

if __name__ == "__main__":
    main()
