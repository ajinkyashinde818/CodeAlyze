import sys
input=sys.stdin.readline
s=input()[:-1]
ans=0
while s:
    a=s[0]
    b=s[-1]
    if a==b:
        s=s[1:-1]
        continue
    elif a=="x":
        s=s[1:]
        ans+=1
        continue
    elif b=="x":
        s=s[:-1]
        ans+=1
        continue
    else:
        print(-1)
        exit()

print(ans)
