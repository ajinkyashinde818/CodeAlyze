def intMap(): return map(int,input().split())
def intList(): return list(map(int, input().split()))

n,k = intMap()
a = intList()
for i in range(n): a[i] -= 1 # 0-base にしておく

moveUntilLoop = 0
loopStart = 0
loopSize = 0

def getLoopInfo(): # ループまでの手数、ループのスタート位置、ループのサイズを得る
    global moveUntilLoop
    global loopStart
    global loopSize
    visited = [0]*n # 訪れた事がある場合は最初に訪れるまでの手数
    moveTime = 0
    pos = 0 # 現在の位置
    
    #ループのスタート位置と、そこまでの手数
    while 1:
        if visited[pos]: break # 過去に訪れた事があれば検索中止
        visited[pos] = moveTime # visited[] に、ここまでの手数を入れる
        moveTime += 1
        pos = a[pos]
    loopStart = pos
    moveUntilLoop = visited[loopStart]

    #ループの長さ
    while 1:
        pos = a[pos]
        loopSize += 1
        if pos == loopStart: break

# k が n より小さい -> 10^5 以下の場合は、実際にやってみる
if k <= n:
    pos = 0
    for i in range(k): pos = a[pos]
    print(pos+1) # 0-base にしたので print 時に戻しておく
    exit()
    
# k > n の場合
getLoopInfo()

# k > n なので k > (loopStart + loopSize)
k -= moveUntilLoop
goal = k % loopSize
pos = loopStart
for _ in range(goal): pos = a[pos]

print(pos+1) # 0-base にしたので print 時に戻しておく
