import sys
read = sys.stdin.buffer.read
readline = sys.stdin.buffer.readline
readlines = sys.stdin.buffer.readlines


s = readline().decode().rstrip()
q = int(readline())

cnt1 = 0
t2 = []
for _ in range(q):
    t = list(readline().decode().rstrip().split())
    t2.append(t)
    if t[0] == '1':
        cnt1 += 1

if cnt1 % 2 != 0:
    s = s[::-1]
s1 = []
s2 = []

for t in t2:
    if t[0] == '1':
        cnt1 -= 1
    else:
        if cnt1 % 2 == 0 and t[1] == '1':
            s1.append(t[2])
        elif cnt1 % 2 != 0 and t[1] == '2':
            s1.append(t[2])
        elif cnt1 % 2 == 0 and t[1] == '2':
            s2.append(t[2])
        else:
            s2.append(t[2])

print(''.join(s1[::-1])+s+''.join(s2))
