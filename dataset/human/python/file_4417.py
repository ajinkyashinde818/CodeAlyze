N=int(input())

def fact(n):
    arr = []
    temp = n
    for i in range(2, int(-(-n**0.5//1))+1):
        if temp%i==0:
            cnt=0
            while temp%i==0:
                cnt+=1
                temp //= i
            arr.append([i, cnt])

    if temp!=1:
        arr.append([temp, 1])

    if arr==[]:
        arr.append([n, 1])

    return arr


garr=0

def idontknow(P):
    global garr
    D=P
    garr=0
    for i in range(1,P+1):
        if D>=i:
            garr+=1
            D=D-i
        else:
            return garr


FFF=fact(N)


ans=0

for i in range(len(FFF)):
    idontknow(int(FFF[i][1]))
    ans+=garr

if N==1:
    print(0)
else:
    print(ans)
