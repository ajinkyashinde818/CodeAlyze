def op2(f, c, r):
  if r == 0:
    if f == "1":
      left.append(c)
    elif f == "2":
      right.append(c)

  if r == 1:
    if f == "1":
      right.append(c)
    elif f == "2":
      left.append(c)

S = input()
Q = int(input())
v = [list(input().split()) for i in range(Q)]
rev = 0
left = []
right = []

for val in v:
  if val[0] == "1":
    if rev == 0:
      rev = 1
    elif rev == 1:
      rev = 0
  elif val[0] == "2":
    op2(val[1], val[2], rev)

nleft = left[::-1]
ans = "".join(nleft + [S] + right)

if rev == 0:
  print(ans)
else:
  print(ans[::-1])
