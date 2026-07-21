import sys
readline = sys.stdin.buffer.readline

def main():
    n, k = map(int, input().split())
    a = list(map(int, input().split()))

    now=1
    flg = 0
    path = [1]
    pathcheck ={1}
    for i in range(min(k,n)):
        now = a[now-1]
        if now in pathcheck:
            flg = -1
            path.append(now)
            break
        path.append(now)
        pathcheck.add(now)


    if flg == 0:
        print(now)
        exit()

    x1 = path.index(now)
    x2 = len(path)-1
    x3 = (k-x1)%(x2-x1)
    print(path[x1+x3])

if __name__ == '__main__':
    main()
