def main():
    k,n = tuple([int(t)for t in input().split()])
    a = [int(t)for t in input().split()]

    l = a[0]
    dist = []
    for a_i in a[1:]:
        dist.append(a_i-l)
        l = a_i
    dist.append(k-a[-1]+a[0])

    print(k-max(dist))

if __name__ == "__main__":
    main()
