import numpy as np
k,n = map(int,input().split())
a = np.array([int(i) for i in input().split()])
'''
隣同士の家の距離が最大のものを求めて、Kメートルから引けばよい
'''
d = np.diff(a)
d = np.append(d, k - a[-1] + a[0])
ans = k - d.max()
print(ans)
