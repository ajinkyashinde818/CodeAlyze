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
n = int(input())
x = factorization(n)
x.sort(key=lambda x: x[-1])
a = [0]
b = 3
for i in range(3,30):
    a.append(b)
    b += i
ans = 0
c = 1
for i in range(len(x)):
    for j in range(len(a)):
        if x[i][1] >= a[c]:
            c += 1
        else:
            break
    ans += c
if n == 1:
    print(0)
else:
    print(ans)
