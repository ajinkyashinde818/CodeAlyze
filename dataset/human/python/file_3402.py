import sys
def factorization(n):
    arr = []
    temp = n
    ele = 1
    for i in range(2, int(-(-n**0.5//1))+1):
        if temp%i==0:
            cnt=0
            while temp % i == 0:
                cnt+=1
                temp //= i
            arr.append([i, cnt])

    if temp!=1:
        arr.append([temp, 1])

    if arr==[]:
        arr.append([n, 1])

    return arr


if __name__ == "__main__":
    n = int(input())
    if n == 1:
        print(0)
        sys.exit(0)
    ar = factorization(n)
    ans = 0
    for ele in ar:
        cnt = ele[1]
        num = 1
        while True:
            if cnt - num < 0:
                break
            else:
                cnt -= num
                num += 1
        ans += num - 1
    print(ans)
