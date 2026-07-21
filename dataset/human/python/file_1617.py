import sys
m,n = map(int,input().split())
mlist = []
nlist = []
for i in range(m):
    a = input()
    mlist.append(list(a))
for i in range(n):
    a = input()
    nlist.append(list(a))

for i in range(m-n+1):
    for j in range(m-n+1):
        frag = 0
        for a in range(n):
            for b in range(n):
                if mlist[i+a][j+b] != nlist[a][b]:
                    frag = 1
            if frag == 1:
                break
        if frag == 0:
            print("Yes")
            sys.exit()
print("No")
