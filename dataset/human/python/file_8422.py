def main():
    k,n = map(int,input().split())
    pos = list(map(int, input().split()))
    dist = []
    for i in range(n-1):
        dist.append(pos[i+1] - pos[i])
    dist.append(k-pos[n-1]+pos[0])
    print(k - max(dist))

if __name__ == '__main__':
    main()
