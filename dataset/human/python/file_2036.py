from itertools import product
N = int(input())
S = input()
MODN = int(10 ** 9 + 7)

'''
keys = list("abcdefghijklmnopqrstuvwxyz")
values = [0] * 26
D = dict(zip(keys, values))

print(D)
exit(0)
'''

D = {}

for ch in S:
  if ch in D:
    D[ch] += 1
  else:
    D[ch] = 1
    
V = list(D.values())
M = len(V)

ans = 1
for i in range(M):
  ans = ans * (V[i]+1) % MODN
  
print(ans - 1)
