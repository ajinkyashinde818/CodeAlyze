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

N = int(input())
flag = 0
if N == 1:
    flag = -1
M = len(factorization(N))
num = [1,3,6,10,15,21,28,36]
ans = 0
for i in range(M):
    for j in range(len(num)):
        if num[j] <= factorization(N)[i][1]:
            ans += 1
        else:
            break

if flag == -1:
    print(0) 
else:
    print(ans)
