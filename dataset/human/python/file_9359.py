def main():
    n,k = map(int,input().split())
    a = list(map(int,input().split()))
    vis = [0 for i in range(n)]
    vis[0] = 1
    fst = [1]
    st = a[0]-1
    while True:
        if vis[st] == 0:
            vis[st] = 1
            fst.append(st+1)
            st = a[st]-1
        else:
            st = fst.index(st+1)
            loop = fst[st:]
            break
    if k < len(fst):
        print(fst[k])
    else:
        k = k - len(fst) + 1
        k = k%len(loop)
        print(loop[k-1])
    

if __name__ == "__main__":
    main()
