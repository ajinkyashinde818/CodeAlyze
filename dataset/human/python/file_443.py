import numpy as np

n = int(input())
a = list(map(int, input().split()))

count  = 0
for i in a:
    if i < 0:
        count += 1
    elif i == 0:
        print(sum(np.abs(a)))
        exit()

if count % 2 == 0:
    print(sum(np.abs(a)))
else:
    a = np.abs(a)
    a.sort()
    b = a[0]
    a = np.delete(a, 0, 0)
    print(sum(a) - b)
