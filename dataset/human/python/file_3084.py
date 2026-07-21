n = int(input())

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

ans = 0
f_arr = factorization(n)
for item in f_arr:
    if item[0] == 1: break

    i = 1
    d = item[1]
    while d > 0:
        d -= i
        if d >= 0:
            ans += 1
        i += 1

print(ans)
