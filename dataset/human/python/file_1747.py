import sys
N, M = map(int, raw_input().split())
A = [raw_input() for i in range(N)]
B = [raw_input() for i in range(M)]
for i in range(N):
    if i + M - 1 >= N:
        break
    for j in range(N):
        if j + M - 1 >= N:
            break
        match = True
        for k in range(M):
            for l in range(M):
                if A[i + k][j + l] != B[k][l]:
                    match = False
                    break
            if not match:
                break
        if match:
            print "Yes"
            sys.exit(0)
print "No"
