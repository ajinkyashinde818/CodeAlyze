import math

def factrize(x):
    f = {}
    if x == 1:
        return f
    tmp = x
    i = 2
    while i**2 <= tmp:
        cnt = 0
        while tmp % i == 0:
            cnt += 1
            tmp = tmp//i
        if cnt > 0:
            f[i] = cnt
        i += 1
    if tmp != 1 or f == {}:
        f[tmp] = 1
    return f
n = int(input())
m = factrize(n)
l = []
for i in m.values():
  l.append(i)
ans=[]
for i in l:
  for j in range(1, 40):
    if i - j >= 0:
      i -= j
      continue
    else:
      ans.append(j-1)
      break
print(sum(ans))
