N = int(input())

def fact(n):
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

ans = 0
if N == 1:
    print(0)
    quit()
for i in fact(N):
    temp = i[1]
    x = 1
    while temp > 0:
        x += 1
        temp -= x
        ans += 1
print(ans)
