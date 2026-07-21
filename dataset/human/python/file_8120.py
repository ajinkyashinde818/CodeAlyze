def int_raw():
    return int(raw_input())

def ss_raw():
    return raw_input().split()

def ints_raw():
    return map(int,ss_raw())

INF = 1<<29

DIV = 10**9+7

K, S = ints_raw()

ans = 0 
for X in xrange(K+1):
    for Y in xrange(K+1):
        Z = S-X-Y
        if Z>=0 and Z<=K:
            ans+=1

print ans
