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

def main():
    N = int(input())
    if N==1:
        print(0)
        return
    factors = factorization(N)
    ans = 0
    for (k,v) in factors:
        count = 1
        tmp = 1
        rest = v
        while True:
            if rest-tmp<tmp+1:
                break
            rest -= tmp
            tmp += 1
            count += 1
        ans += count
    print(ans)

main()
