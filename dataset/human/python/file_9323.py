import numpy as np
n,k = map(int, input().split())
a = input().split()
flag = np.zeros((n))
now = 1
memory = []
for i in range(k):
    if flag[now-1] != 1:
        flag[now-1] = 1
        memory.append(now)
        now = int(a[now-1])        
    else :
        index = memory.index(now)
        num = len(memory) - index
        rest = k - i
        shorten = rest % num
        now = memory[index+shorten]
        break
print(now)
