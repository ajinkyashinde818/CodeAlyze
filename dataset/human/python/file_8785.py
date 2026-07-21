def main():
    k,n = map(int, input().split())
    A = list(map(int, input().split()))

    dis = 0
    for i in range(n-1):
        dis = max(dis, A[i+1]-A[i])
    dis = max(dis, A[0]+(k-A[-1]))
    print(k-dis)


if __name__ == '__main__':
    main()
