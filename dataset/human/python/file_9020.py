import sys
def input(): return sys.stdin.readline().strip()
s=input()
n=len(s)
ks={'eam':'dream','mer':'dreamer','ase':'erase','ser':'eraser'}
while n > 0:
    if n < 3:
        break
    e=s[n-3:n]
    if e not in ks:
        break
    if n < len(ks[e]):
        break
    if s[n-len(ks[e]):n] != ks[e]:
        break
    n-=len(ks[e])
else:
    print('YES')
    sys.exit()
print('NO')
