n,m=[int(i) for i in input().split()]
A=[]
for i in range(n):
    A.append(list(input()))
B=[]
for i in range(m):
    B.append(list(input()))

def choise(x,y):
    C=[]
    for i in range(x,x+m):
        C.append(A[i][y:y+m])
    return C

ans=0
for x in range(n-m+1):
    for y in range(n-m+1):
        if choise(x,y)==B:
            ans+=1
if ans==0:
    print("No")
else:
    print("Yes")
