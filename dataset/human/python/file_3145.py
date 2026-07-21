n = int(input())
if n == 1:
    print(0)
    exit()

def fact(n):
    arr = []
    res = []
    temp = n
    for i in range(2, int(-(-n**0.5//1))+1):
        if temp%i==0:
            cnt=0
            while temp%i==0:
                cnt+=1
                temp //= i
            arr.append([i, cnt])
            res.append(cnt)
    if temp!=1:
        arr.append([temp, 1])
        res.append(1)

    if arr==[]:
        arr.append([n, 1])
        res.append(1)


    return res

alist = fact(n)
#print(alist)
ans = 0
for a in alist:
    for i in range(1,a+3):
        if a < i*(i+1)//2:
            #print(i-1)
            ans += i-1
            break

print(ans)
