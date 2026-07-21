import re
n, m = [int(x) for x in input().split()]
nm = ""
ss = ""
for _ in range(n):
    nm += input()
for i in range(m):
    ss += ".{{{}}}".format(n-m) if i>0 else ""
    ss += input().replace(".","\.")
print("Yes") if re.search(ss,nm) else print("No")
