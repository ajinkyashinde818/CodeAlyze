n,m=map(int,input().split())
a=[]
for i in range(n):
    p=input()
    a.append(p)
b=[]
for i in range(m):
    p=input()
    b.append(p)

def search(h,w):
    for i in range(m):
        if not b[i]==a[h+i][w:w+m]:
            return False
    return True

for i in range(n-m+1):
    for j in range(n-m+1):
        if b[0]==a[i][j:j+m]:
            if search(i,j):
                print("Yes")
                exit()
print("No")
