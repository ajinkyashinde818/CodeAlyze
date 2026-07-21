from collections import Counter
n = int(input())
nmax = 10**6+10
eratos = [0 for i in range(nmax+1)]
prime = []
cnt = 2
while True:
  while cnt <= nmax and eratos[cnt]:
    cnt += 1
  if cnt > nmax:
    break
  eratos[cnt] = 1
  prime.append(cnt)
  for i in range(cnt**2,nmax+1,cnt):
    eratos[i] = 1
pr = []
for i in prime:
  while n%i == 0:
    n //= i
    pr.append(i)
if n > 1:
  pr.append(n)
c = Counter(pr)
ans = 0
for i in c.values():
  for j in range(10):
    if i < j*(j+1)//2:
      ans += j-1
      break
print(ans)
