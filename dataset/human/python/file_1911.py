def check_match(A, B):
    N = len(A)
    M = len(B)
    for i in range(N):
        for j in range(N):
            match = True
            for k1 in range(M):
                for k2 in range(M):
                    if i+k1 >= N or j+k2 >= N or A[i+k1][j+k2] != B[k1][k2]:
                        match = False
                        break
            if match == True:
                return True
    return False

if __name__ == "__main__":
    size = [int(i) for i in input().split()]
    N = size[0]
    M = size[1]
    A = []
    B = []
    for i in range(N):
        A.append(input())
    for i in range(M):
        B.append(input())
    if check_match(A, B) == True:
        print("Yes")
    else:
        print("No")
