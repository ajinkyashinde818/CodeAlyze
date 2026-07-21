n, m = map(int,input().split())
A = [input() for i in range(n)]
B = [input() for i in range(m)]

pt_max = m * m

def b():
    for i in range(n-m+1):
        for j in range(n-m+1):
            pt = 0
            for k in range(m):
                for l in range(m):
                    if A[i+k][j+l] == B[k][l]:
                        pt += 1
            if pt == pt_max:
                return "Yes"
    return "No"

print(b())
