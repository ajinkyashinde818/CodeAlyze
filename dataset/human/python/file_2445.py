from math import ceil

D,G = map(int,input().split())

pc_list = [[i]+list(map(int,input().split())) for i in range(D)]
def rindex_zero(l):
    return len(l) - l[::-1].index(0)-1

def func(g,cnt,l):
    if len(l) == D:
        if g <= 0:
            return cnt
        idx = rindex_zero(l)
        i,p,c = pc_list[idx]
        if g <= 100*(i+1)*(p-1):
            cnt += ceil(g/(100*(i+1)))
            return cnt
        return 10**9
    length = len(l)
    i,p,c = pc_list[length]
#     print(i,p,c,l)
    a = func(g-(100*(i+1)*p+c), cnt+p,l+[1])
    b = func(g, cnt,l +[0])
    return min(a,b)
        
print(func(G,0,[]))
