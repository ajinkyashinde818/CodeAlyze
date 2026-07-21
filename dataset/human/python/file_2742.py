import math
D,G = map(int, input().split())
pclist = [list(map(int, input().split())) for _ in range(D)]
bits=[format(i, '0'+str(D)+'b') for i in range(2**D)]
ans = 10**5
for bit in bits:
    resn = 0
    res = 0
    maxi = bit.rfind('0')+1
    for i, b in enumerate(bit):
        if b == '1':
            resn += pclist[i][0]
            res += pclist[i][0]*100*(i+1)+pclist[i][1]
    if res >= G:
        if resn < ans:
            ans = resn
    elif maxi > 0 and res+(pclist[maxi-1][0]-1)*100*maxi >= G:
        if G-res > 0:
            resn += math.ceil((G-res)/(100*maxi))
        if resn < ans:
            ans = resn
print(ans)
