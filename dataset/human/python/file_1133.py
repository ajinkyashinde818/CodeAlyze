def solve():
    n = int(input())
    a = list(map(int,input().split()))
    b = list(map(int,input().split()))[::-1]
    cnt = [0]*(n+1)
    for x in a: cnt[x]+=1
    for x in b: cnt[x]+=1
    for x in cnt:
        if x  > n :
            print("No")
            return
    l = 0
    r = n-1;
    for i in range(n):
        if a[i] == b[i]:
            if b[l] != a[i] and a[l] != a[i]:
                b[l],b[i] = b[i],b[l]
                l+=1
            else:
                b[r],b[i] = b[i],b[r]
                r-=1
    print("Yes")
    print(" ".join(str(x) for x in b))

solve();
