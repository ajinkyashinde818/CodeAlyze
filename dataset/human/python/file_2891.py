m = int(input())

if m == 1:
    print(0)
    exit()

l = []

for i in range(1, 40):
    p = i * (i+1) / 2
    l.append(p)

def check(n):
    num = 0
    i = 0
    while n >= l[i]:
        num += 1
        i += 1
    return num


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

primers = factorization(m)

ans = 0

for i in primers:
    ans += check(i[1])

print(ans)
