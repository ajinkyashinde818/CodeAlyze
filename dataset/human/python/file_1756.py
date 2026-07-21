def resolve():
    N, M = list(map(int, input().split()))
    A = [input() for i in range(N)]
    B = [input() for i in range(M)]
    for i in range(0, N-M+1):
        for j in range(0, N-M+1):
            flg = True
            for a, b in zip(A[i:i+M], B):
                if a[j:j+M] != b:
                    flg = False
                    break
            if flg:
                print("Yes")
                return
    print("No")
if '__main__' == __name__:
    resolve()
