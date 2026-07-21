import numpy as np

n = input()
a = np.array([int(num) for num in input().split(' ')])

min = 100000000000
sunuke = 0
araiguma = a.sum()
for i in range(0, len(a) - 1):
    sunuke += a[i]
    araiguma -= a[i]
    dif = abs(sunuke - araiguma)
    if dif < min: min = dif
print(min)
