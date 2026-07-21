import bisect
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
    n = int(input())
    if n == 1:
        print(0)
        return
    ans = 0
    p = factorization(n)

    for i, pp in enumerate(p):
        tmp = pp[1]
        ary = [0] * (tmp+1)
        cnt = 1
        while tmp > 0:
            ans += 1
            tmp -= cnt
            if tmp <= cnt:
                cnt += 1
                break
            if tmp < 0:
                tmp += cnt

            cnt += 1
    print(ans)


if __name__=='__main__':
    main()
