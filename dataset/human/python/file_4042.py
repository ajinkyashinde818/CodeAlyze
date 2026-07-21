N = int(input())

def factorization(n):
    a = []
    temp = n
    for i in range(2, int(-(-n**0.5//1))+1):
        if temp%i==0:
            cnt=0
            while temp%i == 0:
                cnt += 1
                temp //= i
            a.append([i, cnt])

    if temp != 1:
        a.append([temp, 1])

    if a == []:
        a.append([n, 1])

    return a

result = factorization(N)

count = 0
for p, i in result:
    if p == 1:
        continue
    s = 0
    for k in range(1, i+1):
        if s + k > i:
            break
        else:
            N /= p ** k
            count += 1
            s += k
print(count)
