import sys
S = input()
Q = int(input())
pin = 0
left = ''
right = ''
for i in range(Q):
  t = list(sys.stdin.readline().split())
  if int(t[0]) == 1:
    pin += 1
  else:
    if int(t[1]) % 2 == pin % 2 :
      right = right + t[2]
    else:
      left = t[2] + left
S = left + S + right
if pin % 2 == 1:
  S = S[::-1]
print(S)
