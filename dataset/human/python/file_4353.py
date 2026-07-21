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
fac_list = factorization(n)
a = [0]*len(fac_list)
for i in range(len(fac_list)):
    a[i] = fac_list[i][1]
t = 0
if n == 1:
        print(0)
else:
    for j, aa in enumerate(a):
        p = 0
        for i in range(1,aa+1):
            p += i
            if p <= aa:
                t += 1
            else:
                break
    print(t)
