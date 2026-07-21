d,g=map(int,input().split())
l = [list(map(int,input().split())) for i in range(d)]
def f(t,s):
    if t==-1:
        return float('inf')
    num = min(l[t][0],s//((t+1)*100))
    k = num*(t+1)*100
    if num==l[t][0]:
        k += l[t][1]
    if k<s:
        num += f(t-1,s-k)
    return min(num,f(t-1,s))
 
print(f(d-1,g))
