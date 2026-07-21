def f():
    n,k=map(int,input().split())
    l=list(map(int,input().split()))
    now=1
    for d in range(k.bit_length()):
        k,f=divmod(k,2)
        if f:now=l[now-1]
        l=tuple(l[i-1]for i in l)
    print(now)
if __name__ == "__main__":
    f()
