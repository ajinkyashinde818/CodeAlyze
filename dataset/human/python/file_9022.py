s = str(input())
alist = ["dream", "dreamer", "erase", "eraser"]
ans = False

def backwards(x):
  return x[::-1]
s = backwards(s)
alist = [backwards(i) for i in alist]

t = ""
start = 0
for i in range(len(s)+1):
  if s[start:i] in alist:
    t+=s[start:i]
    start = i
if s==t:
  print("YES")
else:
  print("NO")
