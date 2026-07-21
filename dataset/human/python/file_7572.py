from collections import deque
s = deque(input())
n = int(input())
re = 0
st = ''
en = ''
for i in range(n):
    a = list(input().split())
    if a[0]=='1':
        re = 1 if re==0 else 0
    else:
        if a[1]=='1':
            if re==0:
                s.appendleft(a[2])
            else:
                s.append(a[2])
        else:
            if re==0:
                s.append(a[2])
            else:
                s.appendleft(a[2])
if re==1:
    s.reverse()
res = list(s)
print(''.join(res))
