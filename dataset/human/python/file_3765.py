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

n=int(input())
if n==1:
    print(0)
    exit()
ans=0
t=factorization(n)

fg=[]
for i in range(1,16):
    fg.append(i*(i+1)//2)

tmp=[]
for i in range(len(t)):
    cnt=0
    for j in range(len(fg)):
        if t[i][1]>=fg[j]:
            cnt=(j+1)
    ans+=cnt

print(ans)
