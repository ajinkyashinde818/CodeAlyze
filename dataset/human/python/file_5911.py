def intminus(i):
    return int(i) - 1
def main(): 
    
    n = int(input())
    A = list(map(intminus, input().split()))
    B = list(map(int, input().split()))
    C = list(map(int, input().split()))

    cnt = 0
    for i in range(len(A)):
        cnt += B[A[i]]
        if i != 0 and A[i-1]+1 == A[i]:
            cnt += C[A[i-1]]

    print(cnt)
    
if __name__ == "__main__":
    main()
