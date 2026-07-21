import sys
if __name__ == '__main__':

    N,M = map(int, input().split())

    A = []
    B = []
    for i in range(N):
        A.append(input())
    for i in range(M):
        B.append(input())

    char = B[0][0]
    matc = False
    for i in range(N-M+1):
        for j in range(N-M+1):
            if A[i][j] == char:
                matc = True
                for k in range(M):
                    for l in range(M):
                        if A[i+k][j+l] == B[k][l]:
                            matc = True
                        else:
                            matc = False
                            break
                    if not matc:
                        break
                if matc == True:
                    print("Yes")
                    sys.exit(0)

    if matc == True:
        print("Yes")
    else:
        print("No")
