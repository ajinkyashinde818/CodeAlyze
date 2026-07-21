def main():
    n = int(input())
    a = [int(i) for i in input().split()]

    cnt = 0
    for i in range(n):
        if a[i] < 0:
            a[i] = -a[i]
            cnt+= 1
    if cnt %2 == 0:
        print(sum(a))
    else:
        a.sort()
        print(sum(a)- 2*a[0])


main()
