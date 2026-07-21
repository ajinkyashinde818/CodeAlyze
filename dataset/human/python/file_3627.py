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
    import sys
    N = int(input())
    fact = factorization(N)
    if fact[0][0] == 1:
        print(0)
        sys.exit()
    ans = 0
    for f, num in fact:
        for i in range(1, num+1):
            if num < i:
                break
            num -= i
            ans += 1
    print(ans)
main()
