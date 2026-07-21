import sys
def input(): return sys.stdin.readline().strip()
S = input()
Q = int(input())
flag = True
f = ''
b = ''
for i in range(Q):
    q = list(input().split())
    if q[0] == '1':
        flag = not flag
    else:
        if flag:
            if q[1] == '1':
                f = q[2] + f
            else:
                b += q[2]
        else:
            if q[1] == '1':
                b += q[2]
            else:
                f = q[2] + f
S = f + S + b
if not flag:
    S = S[::-1]
print(S)
