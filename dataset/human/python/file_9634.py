def main():
    n, k = map(int, input().split())
    a = list(map(int, input().split()))

    num = 1
    l = []
    s = [1]*n

    while s[num-1]:
        l.append(num)
        s[num-1] = 0
        num = a[num-1]

    if l.index(num) <= k:
        l2 = l[l.index(num):]
        kk = (k-len(set(l)-set(l2)))%len(l2)
        print(l2[kk])
    else:
        print(l[k])

main()
