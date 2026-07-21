import bisect
n=input()
a=list(map(int,input().split()))
if n=="2":print(abs(a[0]-a[1]))
else:
    s=[]
    x=0
    for i in a[:-1]:
        x+=i
        s.append(x)
    s.sort()
    s.append(float("inf"))
    y=bisect.bisect_left(s,sum(a)/2)
    print(min(abs(sum(a)-2*s[y]),abs(sum(a)-2*s[y-1])))
