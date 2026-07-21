def main():
    N = int(input())
    A = list(map(int, input().split(" ")))
    zero = 0
    neg = 0
    m = float("inf")
    for i in range(N):
        if A[i] == 0:
            zero += 1
        if A[i] < 0:
            neg += 1
        A[i] = abs(A[i])
        m = min(m, A[i])

    neg = neg % 2 
    if neg == 0:
        result = sum(A)
    else:
        if zero:
            result = sum(A)
        else:
            result = sum(A) - 2*m
    print(result)
    return 

if __name__ == "__main__":
    main()
