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
N=int(input())
A=factorization(N)
ans=0
if N==1:
 print(0)
else:
 for i in range(len(A)):
  ans+=int((2*A[i][1]+0.25)**(0.5)-0.5)
 print(ans)
