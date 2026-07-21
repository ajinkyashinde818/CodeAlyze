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
p = factorization(N)
def cou(n):
    temp = n
    count = 1
    out = 0
    while temp - count >= 0:
        temp -= count
        count += 1
        out += 1
    return out

ans = []

for i in range(len(p)):
    ans.append(cou(p[i][1]))

answer = 0 if N == 1 else sum(ans)
print(answer)
