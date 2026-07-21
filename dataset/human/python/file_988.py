import sys
mod = 10**9 + 7
N=int(input())
S = input()
leftL = 0
leftR = 0
ISR = []
for s in S:
  if s=="B":#leftL-leftRと同符号
    isR = abs(leftL-leftR)
  else:
    isR = int(not bool(abs(leftL-leftR)))
  if isR:
    leftR = (leftR+1)%2
  else:
    leftL = (leftL+1)%2
  ISR.append(isR)

if sum(ISR)!=N:
  print(0)
  sys.exit()

zanki = 0
ans = 1
for i in ISR:
  if zanki<0:
    print(0)
    sys.exit()
  if i:#Rの場合
    ans *= zanki
    zanki -= 1
  else:
    zanki += 1
  ans %= mod

for j in range(1,N+1):
  ans = (ans*j)%mod

print(ans)
