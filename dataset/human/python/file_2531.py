from sys import setrecursionlimit
from operator import itemgetter
from math import ceil
def main():
    D,G = map(int,input().split())
    PC = [list(map(int,input().split())) for _ in range(D)]
    ans = float("inf")
    for i in range(2**D):
        done = [False]*D
        tmp = 0
        q = 0
        cnt = i
        point = 0
        while cnt > 0:
            if cnt%2 == 1:
                done[point] = True
                tmp += PC[point][0]*(100*(point + 1)) + PC[point][1]
                q += PC[point][0]
            point += 1
            cnt //= 2
        if tmp < G:
            for j in range(D):
                if not(done[D - j - 1]):
                    score = 100*(D - j)
                    num = min(ceil((G - tmp) / score),PC[D - j - 1][0])
                    tmp += num*score
                    q += num
                    if tmp < G:
                        q = float("inf")
                    break
                
        ans = min(q,ans)
    print(ans)
    return

if __name__ == "__main__":
    main()
