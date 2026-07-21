n=int(input())

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

yakusu = factorization(n)

ans = 0

for i in range(len(yakusu)):
    l = yakusu[i]
    a,b = l[0],l[1]
    j = 1
    k = 2
    if a != 1:
        while b>=j:
            ans += 1
            j += k
            k += 1
if n==1:
    print(0)
else:
    print(max(ans,1))
