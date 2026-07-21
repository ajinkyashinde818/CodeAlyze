S = input()
Q = int(input())

res = S

is_rev = False

before = []
after = []

def add_char(s, f, c, is_rev):
  if(f == "1"):
    before.append(c)
  else:
    after.append(c)

for _ in range(Q):
  q = input().split()
  
  if(q[0] == '1'): # Ti = 1
    is_rev = not is_rev
    before, after = after, before
  
  else: #Ti = 2
    add_char(res, q[1], q[2], is_rev)

before.reverse()

res = "".join(before) + (res[::-1] if is_rev else res) + "".join(after)

print(res)
