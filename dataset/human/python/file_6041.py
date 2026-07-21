import numpy as np
N = int(input())
A, B, C = [list(map(int, input().split())) for _ in range(3)]
score=0
pred_i=np.inf
for i in A:
    if pred_i+1 ==i:
        score=score+C[i-2]+B[i-1]
    else:
        score+=B[i-1]
    pred_i=i
print(score)
