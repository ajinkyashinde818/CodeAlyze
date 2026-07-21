def resolve():
    n, k = map(int, input().split())
    a = list(map(int, input().split()))
    check=[-1]*n
    iti=0
    rireki=[]
    while True:
        iti=a[iti]-1
        if check[iti]==0:
            mae=rireki.index(iti)
            Mae=rireki[:mae]
            Loop=rireki[mae:]
            roop=len(Loop)
            break
        rireki.append(iti)

        check[iti]=0
    if k <= mae:
        print(Mae[k-1]+1)
    else:
        k-=mae
        print(Loop[(k%roop)-1]+1)
resolve()
