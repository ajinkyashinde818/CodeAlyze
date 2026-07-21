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
N = int(input())
N = factorization(N)
count = 0

if N[0][0] == 1:
    print(0)
else:
    for i in range(0,len(N)):
        t = 0
        for j in range(1,N[i][1]+1):
            t += j
            if N[i][1] == t:
                count += j
                break
            elif N[i][1] < t:
                count += j-1
                break
            else:
                pass
    print(count)
