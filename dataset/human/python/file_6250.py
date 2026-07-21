import sys
n = [int(i) for i in sys.stdin.readline().rstrip()[::-1]]
ans = 0
i = 0
p = [n[i],10 - n[i]]
now = [0,0]
i += 1
ans = min(p[0], p[1] + 1)
for i in range(1,len(n)):
  now[0] = min(p[0] + n[i]%10, p[1] + n[i]%10 + 1)
  now[1] = min(p[0] + 10 - n[i]%10, p[1] + 9 - n[i]%10)
  ans = min(now[0], now[1] + 1)
  p[0],p[1] = now[0],now[1]
print(ans)
