N = int(input())

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

    return arr

fact = factorization(N)
s = 0
for p, e in fact:
    s += int(pow(e * 2 + 0.25, 0.5) - 0.5)
print(s)
