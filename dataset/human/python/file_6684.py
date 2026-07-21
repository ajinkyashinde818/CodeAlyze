import sys
input = sys.stdin.readline
s=input().replace('\n','')
q=int(input())
num1=0
sento=''
matsubi=''

for i in range(q):
    query=input()
    if query[0]=='1':
        num1+=1
    else:
        query=query.replace('\n','')
        _,f,c=map(str,query.split())
        if f=='1':
            if num1%2==0:
                sento=c+sento
            else:
                matsubi+=c
        else:
            if num1%2==0:
                matsubi+=c
            else:
                sento=c+sento
ans=sento+s+matsubi
if num1%2==0:
    print(ans)
else:
    print(ans[::-1])
