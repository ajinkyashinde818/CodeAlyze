import numpy as np
N = int(input())
A = np.array(input().split(),dtype=np.int64)

Acum = A.cumsum()
total = Acum[-1]
diff = np.abs(Acum - (total-Acum))

answer = diff[:-1].min() # 最後の1枚はアライさん

print(answer)
