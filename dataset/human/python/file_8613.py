def main():
    K,N = map(int,input().split())
    A = [int(i) for i in input().split()]
    A = A + [A[0] + K ]
    dis = []
    for i in range(N):
        dis.append(A[i+1] - A[i])
    print(sum(dis) - max(dis))


if __name__ == '__main__':
    main()
