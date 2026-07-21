def flipping(n,a):
    c = list(filter(lambda x:x<0,a))
    b = list(map(lambda x:abs(x),a))
    if len(c)%2==0:
        return sum(b)
    if len(c)%2!=0:
        return sum(b)-2*min(b)
    return b
n = int(input())
a=list(map(int, input().split()))
print(flipping(n,a))
