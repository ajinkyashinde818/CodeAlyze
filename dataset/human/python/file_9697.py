ii = lambda:int(input())
mi = lambda:list(map(int,input().split()))
ix = lambda x:list(input() for _ in range(x))
mix = lambda x:list(mi() for _ in range(x))
iix = lambda x:list(int(input()) for _ in range(x))
##########
def main(n,k,a):
    zan = 0
    count = 0
    p = 1
    t = {i:-1 for i in range(n)}
    t[0] = 0
    for i in range(k):
        count += 1
        p = a[p-1]
        if t[p-1] == -1 :
            t[p-1] = count
        else:
            loop = count - t[p-1]
            zan = (k- t[p-1]) % loop
            break
    for i in range(zan):
        p = a[p-1]
    return p

n,k = mi()
a = mi()
print(main(n,k,a))
