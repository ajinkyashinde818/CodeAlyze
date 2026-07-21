import numpy as np

N = int(input())
A = np.array(list(map(int, input().split())))

ans = np.zeros(1, dtype=np.uint64)
even_odd = 0
mini = 1000000000

for i in A:
    if(i < 0):
        even_odd = (even_odd + 1) % 2
    ans += abs(i)
    if(mini > abs(i)):
        mini = abs(i)
        
if(even_odd == 0):
    print(ans[0])
else:
    print((ans - (mini * 2))[0])
