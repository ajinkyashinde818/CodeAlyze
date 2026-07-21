n = int(input())

if n == 1:
    print(0)
    exit()

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
ans = factorization(n)
s= 0
for i in range(len(ans)):
    now = 1
    while(ans[i][1] >= 0):
        ans[i][1] -= now
        #print(ans[i][0],now)
        s += 1
        now += 1
    s -= 1
print(s)
