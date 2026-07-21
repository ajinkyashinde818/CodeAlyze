N = int(input())
if N == 1:
    print(0)
    quit()
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
def sousa(n):
    x = [1,3,6,10,15,21,28,36,45,55]
    for i in range(10):
        a = x[i]
        if n < a:
            return i
            break
bunkai = factorization(N)
ans = 0
for i in range(len(bunkai)):
    c = bunkai[i][1]
    ans += sousa(c)
print(ans)
