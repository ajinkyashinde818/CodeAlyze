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
F = factorization(N)
f = len(F)
answer = 0
for i in range(f):
    count = 1
    if F[i][0] == 1:
        break
    if F[i][1] == 1:
        answer += 1
    else:
        while True:
            if F[i][1] < count:
                break
            else:
                F[i][1] = F[i][1] - count
                count += 1
                answer += 1

print(answer)
