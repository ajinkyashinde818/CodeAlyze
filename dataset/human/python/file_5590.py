import re
s=input()
c=''
for i in s:
    if i!='x':
        c+=i
if c!=c[::-1]:
    print(-1)
    exit()
n=len(s)
l,r=0,n-1
ans=0
while(r-l>0):
    if s[l]!=s[r]:
        if s[l]=='x':
            ans+=1
            l+=1
        elif s[r]=='x':
            ans+=1
            r-=1
    else:
        l+=1
        r-=1
print(ans)
