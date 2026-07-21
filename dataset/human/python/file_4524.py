n = int(input())

if n == 1:
    print(0)
    exit(0)

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

def count(m):
    count = 0
    for i in range(1, 10**12+1):
        if m >= i :
            m -= i
            count += 1
        else:
            return count


bun = factorization(n)

kazu = len(bun)

#if kazu == 1 and bun[0][1] ==1:
#    print(0)
#    exit(0)


countup = 0
for i in range(kazu):
    countup += count(bun[i][1])

print(countup)
