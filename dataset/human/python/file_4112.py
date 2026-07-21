N=int(input())

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
  
A=0
z=1
q=factorization(N)
if N==1:
    print(0)
else:  
    for i in range(len(q)):
        for j in range(1,101):
            z=q[i][0]**j
            if N%z==0:
                A+=1
                N=N/z
            else:
                break
    print(A)
