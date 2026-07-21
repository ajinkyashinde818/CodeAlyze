n=int(input())
s=input()
mod=10**9+7

def get_num(s, iii):
    if s=="B":
        for i in range(iii,-1,-1):
            if i%2==1:
                return i
    else:
        for i in range(iii,-1,-1):
            if i%2==0:
                return i

ans=1
thread=1 if s[0]=="B" else 0
for i in range(1, 2*n):
    cnt=i+1 if i<n else 2*n-i
    if s[i]=="B":
        if thread%2==0:
            thread+=1
        else:
            ans*=thread
            thread-=1
    elif s[i]=="W":
        if thread%2==0:
            ans*=thread
            thread-=1
        else:
            thread+=1
    ans%=mod

if thread==0:
    for i in range(1, n+1):
        ans*=i
        ans%=mod
    print(ans)
else:
    print(0)
