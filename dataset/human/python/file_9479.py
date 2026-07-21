import sys
sys.setrecursionlimit(10**7)

def teleport(city, end, teleportmap, count=1):

    next_city = teleportmap[city]

    if count == end:
        return next_city

    else:
        return teleport(next_city, end, teleportmap, count+1)

n, k = map(int,input().split())
a = list(map(int, input().split()))
teleportmap = dict(zip(range(1, len(a)+1), a))

if k <= n:
    print(teleport(1, k, teleportmap))

else:
    countmap = [0]*n
    countmap[0] = 1

    next_city =1
    for _ in range(1, n+1):
        next_city = a[next_city-1]
        countmap[next_city -1] += 1
        if countmap[next_city -1] == 2:
            start = next_city
            break

    roop = {}
    for j in range(1, n+1):
        roop[start] = teleportmap[start]
        start = roop[start]
    
    num_r = len(roop)

    num_until_r= 0
    for m in teleportmap.keys():
        if m not in roop and countmap[m-1] != 0:
            num_until_r += 1
    
    k_r = k - num_until_r
    num_end = k_r%num_r

    if num_end == 0:
        print(next_city)
        
    else:
        print(teleport(next_city, num_end, roop))
