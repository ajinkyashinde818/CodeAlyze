n,k,s=map(int,input().split())
a=s//2
b=s-a
x=[]
if s==10**9:
    import sys
    for i in range(n):
        if i>=k:
            x.append(1)
            continue
        x.append(s)
    print(' '.join([str(i) for i in x]))
    sys.exit()
for i in range(n):
    if i>=k:
        x.append(s+1)
        continue
    x.append(s)
print(' '.join([str(i) for i in x]))
