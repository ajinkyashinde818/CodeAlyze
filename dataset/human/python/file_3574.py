a=int(input())
ans =0


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
b = factorization(a)
for i in range(len(b)):
    count=0
    c = b[i][1]

    for j in range(1,40):
        if c - j >= 0:
            c -= j
            count += 1
        else:
            ans += count
            break
if a ==1:
    print(0)
else:
    print(ans)
