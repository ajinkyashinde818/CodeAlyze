def resolve():
    N, M = map(int, input().split())
    A = []
    B = []
    ans = 0
    for _ in range(N):
        a = input()
        A.append(a)
    for __ in range(M):
        b = input()
        B.append(b)
    for i in range(N-M+1):
        for j in range(N-M+1):
            flag = 0
            for p in range(M):
                for q in range(M):
                    if A[i+p][j+q] != B[p][q]:
                        flag = 1
            if flag == 0:
                ans = 1
    print("Yes" if ans == 1 else "No")
resolve()
