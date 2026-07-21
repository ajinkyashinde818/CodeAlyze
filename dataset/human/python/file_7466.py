import sys;input=sys.stdin.readline
S=input().strip()
n=len(S)
Qs = []
for c in S:
    Qs.append((1,1,c))
for q in range(int(input())):
    x = input().strip().split()
    if len(x) == 1:
        Qs.append((0,0,0))
    else:
        n+=1
        Qs.append((1,int(x[1])-1,x[2]))

rs = [0]*n
i,j=0,n-1
f=1
for t, tt, c in Qs[::-1]:
    if t==0:
        f=1-f
    else:
        if (tt+f)%2:
            rs[i] = c
            i+=1
        else:
            rs[j] = c
            j -= 1
print("".join(rs))
