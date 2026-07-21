def InputToInt():
    A = input().split()
    for i in range(len(A)):
        A[i] = int(A[i])
    return A
    
if __name__ == '__main__':
    N = int(input())
    A = InputToInt()
    B = InputToInt()
    C = InputToInt()

    c = sum(B)
    for i in range(N-1):
        if A[i+1] == A[i]+1:
            c += C[A[i]-1]
    print(c)
