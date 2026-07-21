from sys import stdin
def S(): return stdin.readline().rstrip()

a = S()
strl = ['dream','dreamer','erase','eraser']
t = ''
for i in range(len(a)-1,-1,-1):
    if 7<len(t):
        print('NO')
        exit()
    else:
        t = a[i]+t
        if t in strl:
            t = ''

print('YES')
