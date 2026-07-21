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

if n == 1:
    print(0)
    quit()
f = factorization(n)
ans = 0
c = len(f)
for i in range(c):
    s = 0
    g = f[i][1]
    for j in range(g):
        s += j + 1
        f[i][1] -= j+1
        if s > g:
            break
        ans += 1
print(ans)
