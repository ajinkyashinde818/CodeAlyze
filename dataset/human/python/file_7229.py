from collections import deque

s = list(input())
q = int(input())

mae = deque()
usi = deque()
k = 0
m = 0
for i in range(q):
    a = input().split()
    if(a[0] == '1'):
        k += 1
    if(a[0] == '2'):
        if(k %2 == 0):
            if(a[1] == '1'):
                mae.appendleft(a[2])
            else:
                usi.append(a[2])
        else:
            if(a[1] == '1'):
                usi.append(a[2])
            else:
                mae.appendleft(a[2])
mae = list(mae)
usi = list(usi)

if(k % 2 == 1):
    mae = mae[::-1]
    usi=usi[::-1]
    s = s[::-1]
    s = ''.join(usi+s+mae)
else:
    s = ''.join(mae+s+usi)
print(s)
