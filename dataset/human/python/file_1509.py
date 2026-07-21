N, M = map(int, raw_input().split())
A = [raw_input() for i in range(N)]
B = [raw_input() for i in range(M)]
def judge():
    for i in range(N-M+1):
        for j in range(N-M+1):
            ok = True
            for r in range(M):
                for c in range(M):
                    if A[i+r][j+c] != B[r][c]:
                        ok = False
            if ok:
                return "Yes"
    return "No"
print judge()
