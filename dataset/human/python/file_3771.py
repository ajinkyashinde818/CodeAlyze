def f(n):
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
ct=0
a=f(n)
for i in range(len(a)):
    ct2=0
    ct3=1
    c=a[i][1]
    while 1:
        ct2+=ct3
        if ct2==c:
            ct+=ct3

            break
        elif ct2>c:
            ct+=ct3-1
            break
        ct3+=1
if n==1:
    ct=0
print(ct)
