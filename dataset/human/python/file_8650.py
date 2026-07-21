if __name__ == '__main__':
    s = input().rstrip().split(' ')
    K = int(s[0])
    N = int(s[1])
    s = input().rstrip().split(' ')
    A = [int(elem) for elem in s]
    B = [[0,0] for elem in s]
    for i in range(len(A)-1):
        B[i][0] = abs(A[i]-A[i+1])
        B[i+1][1] = abs(A[i]-A[i+1])

    B[len(A)-1][0] = K-abs(A[len(A)-1]-A[0])
    B[0][1] = K-abs(A[len(A)-1]-A[0])

    ans = float('inf')

    for elem in B:
        if(ans > K-elem[0]):
            ans = K-elem[0]
        if(ans > K-elem[1]):
            ans = K-elem[1]

    print(ans)
