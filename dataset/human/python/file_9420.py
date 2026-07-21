def getlooptime(warpmap, start='1'):
    warpmap_ = warpmap.copy()    
    counter = 0

    for _ in range(N):

        counter += 1

        nextmap = warpmap_[start]

        if type(nextmap) == int:
            return counter - 1, (counter - 1) - (nextmap - 1)
        
        warpmap_[start] = counter
        start = nextmap

def getterminal(warpmap, n, start):
    warpmap_ = warpmap.copy()

    if n == 0:
        return start
    else:
        for _ in range(1, n + 1):
            nextmap = warpmap_[start]
            start = nextmap

        return nextmap


N, K = map(int, input().split())
A = list(map(int, input().split()))

warpmap = {}

for town_num, to_warp in enumerate(A):
    
    town_num = town_num + 1
    warpmap[f"{town_num}"] = f"{to_warp}"

pasttime, looptime = getlooptime(warpmap=warpmap, start='1')

if K > pasttime:
    print(getterminal(warpmap=warpmap, n=(K - pasttime) % looptime, start=getterminal(warpmap=warpmap, n=pasttime, start='1')))
else:
    print(getterminal(warpmap=warpmap, n=K, start='1'))
