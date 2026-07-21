import numpy as np
n, m = map(int, input().split())
A = [list(input()) for _ in range(n)]
B = [list(input()) for _ in range(m)]

A, B = np.array(A), np.array(B)

for i in range(n-m+1):
    for j in range(n-m+1):
        tmp = A[i:i+m, j:j+m]
        # 普通にtmp == Bで比較すると要素ごとの一致不一致が返るので,
        # 全体の一致を判定するall()を利用する
        if (tmp == B).all():
            print("Yes")
            exit()
else:
    print("No")
