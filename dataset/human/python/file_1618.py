def fun():
     print('ac')
     print('AC')
     print('ACAC')
     print('ac')
N,M=map(int,input().split())
ls=[]
l=[]
result=0

for i in range(N):
     x=input()
     ls.append(x)
for i in range(M):
     y=input()
     l.append(y)
for i in range(0,N-M+1):
     k=0
     for t in range(0,N-M+1):
          if l[k] == ls[i][t:t+M]:
               for g in range(1,M):
                    if l[g]!=ls[g+i][t:t+M]:
                         break
               else:
                    result=1
if result==1:
     print('Yes')
else:
     print('No')
