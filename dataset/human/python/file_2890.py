n=int(input())
m=n

def factorization(n):
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


a=factorization(n)
#print(a)

def makearray(l):
    arr=[]
    for i in range(len(l)):
        for j in range(1,l[i][1]+1):
            arr.append(l[i][0]**j)
    arr.sort()
    return arr

b=makearray(a)
#print(b)
cnt=0

for i in b:
    if n%i==0:
        cnt+=1
        n//=i
        #print(i)
        #print('a')

if m==1:
    print(0)
else:
    print(cnt)
