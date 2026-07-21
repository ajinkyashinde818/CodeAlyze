n=int(input())
def soinsu(n):
    arr = []
    now = n
    for i in range(2, -int(-n**0.5)+1):
        if now%i==0:
            cnt=0
            while now%i==0:
                cnt+=1
                now //= i
            arr.append([i, cnt])
    if now>1:
        arr.append([now,1])
    return arr

soi = soinsu(n)
cand=[ s[1] for s in soi]

aida = [(i)*(i+1)//2 for i in range(1,45)]
import bisect

print(sum(bisect.bisect(aida,c) for c in cand) )
