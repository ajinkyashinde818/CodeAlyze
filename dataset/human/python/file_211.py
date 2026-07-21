from itertools import combinations
import sys
N=int(input())
flag=True
for k in range(1000):
    s=(k*(k+1))//2
    if s==N:
        flag=False
        break
if flag:
    print('No')
    sys.exit()
table=[[k] for i in range(k+1)]
s=1
for elem in combinations(range(k+1),2):
    table[elem[0]].append(s)
    table[elem[1]].append(s)
    s+=1
print('Yes')
print(k+1)
for i in range(k+1):
    print(' '.join(map(str,table[i])))
