N, M = map(int,input().split())
A = [list(input()) for i in range(N)]
B = [list(input()) for i in range(M)]

Diff = N - M + 1
if Diff == 1 :
    if A == B :
        print("Yes")
    else :
        print("No")
    exit()

def partofA(i, j) :
    Ans = []
    for x in range(M) :
        Ansx = []
        for y in range(M) :
            Ansx.append(A[x+i][y+j])
        Ans.append(Ansx)
    return Ans

for i in range(Diff) :
    for j in range(Diff) :
        if partofA(i,j) == B :
            print("Yes")
            exit()

print("No")
