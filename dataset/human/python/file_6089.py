import sys
n = int(sys.stdin.readline())
lia = list(map(int, sys.stdin.readline().split()))
lib = list(map(int, sys.stdin.readline().split()))
lic = list(map(int, sys.stdin.readline().split()))
s = sum(lib)
li = []
i = 0
while i < n-1:
  if lia[i+1] - lia[i] == 1:
    li.append(lia[i]-1)
  i += 1
for i in li:
  s += lic[i]
print(s)
