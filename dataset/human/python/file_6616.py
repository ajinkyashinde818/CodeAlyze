import sys
readline = sys.stdin.readline
read = sys.stdin.read

S = input()
Q = int(input())

u = ''
t = ''

r = False
for _ in range(Q):
    q = readline().split()
    if q[0] == '1':
        u, t = t, u
        r = not r
    else:
        if q[1] == '1':
            t += q[2]
        else:
            u += q[2]
            
if r:
    print(t[::-1]+S[::-1]+u)
else:
    print(t[::-1]+S+u)
