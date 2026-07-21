def main():
    n = int(input())
    a = list(map(int, input().split()))
    nn = (n*(n+1))//2
    sum_ = sum(a)
    a += [a[0]]
    cnt = sum_//nn
    if sum_ % nn != 0:
        print("NO")
        return 0
    ans = 0
    for i in range(n):
        p = a[i]-a[i+1]+cnt
        if p % n != 0 or p//n<0:
            print("NO")
            return 0
        ans += p//n
    if ans == cnt:
        print("YES")
    else:
        print("NO")


main()
