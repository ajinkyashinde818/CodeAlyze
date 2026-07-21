import sys
input = sys.stdin.buffer.readline

def main():
    N,M = map(int,input().split())
    a = list(map(int,input().split()))
    go = [False]*N
    
    roop = [1]
    now = 1
    while True:
        go[now-1] = True
        now = a[now-1]
        if go[now-1]:
            break
        else:
            roop.append(now)
            go[now-1] = True

    ind = roop.index(now)
    r = len(roop)-ind
    if M < ind:
        print(roop[M])
    else:
        M -= ind
        M %= r
        M += ind
        print(roop[M])
    
if __name__ == "__main__":
    main()
