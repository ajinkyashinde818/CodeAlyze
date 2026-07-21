nm=list(map(int,input().split()))
a,b=[],[]
for i in range(nm[0]):
    a.append(input())
for j in range(nm[1]):
    b.append(input())

def check(i,j):
    result="match"
    for k in range(nm[1]):
        if b[k]==a[i+k][j:j+nm[1]]:
            continue
        else:
            result="unmatch"
            break
    return result

flag=0
for i in range(nm[0]-nm[1]+1):
    if flag==0:
        for j in range(nm[0]-nm[1]+1):
            if check(i,j)=="match":
                print("Yes")
                flag=1
                break
if flag==0:
    print("No")
