def main():
    k, n = map(int, input().split())
    a = list(map(int, input().split()))
    a.append(a[0]+k)
    print(k-sorted([a[i+1] - a[i] for i in range(len(a)-1)])[-1])


if __name__ == '__main__':
    main()
