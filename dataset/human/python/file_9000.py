import sys
readline = sys.stdin.buffer.readline

s = readline().rstrip().decode('utf-8')
s = s[::-1]
n = len(s)
l = ["dreamer","dream","eraser", "erase"]
for i in range(4):
    l[i] = l[i][::-1]

i=0
while i < n:
    flag = 0
    for j in range(4):
        if i+len(l[j]) <= n and s[i:i+len(l[j])] == l[j]:
            i += len(l[j])
            flag = 1
            break
    if not flag:
        print("NO")
        exit()
print("YES")
