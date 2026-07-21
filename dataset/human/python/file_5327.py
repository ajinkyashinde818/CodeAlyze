from sys import exit
N,M = [int(n) for n in input().split()]
Mat = [set() for _ in range(N)]#Nの隣接リスト
for i in range(M):
    a,b = [int(n) for n in input().split()]
    Mat[a-1].add(b-1)
    Mat[b-1].add(a-1)
N-=1
for ne in Mat[0]:
    # print(N,Mat[ne])
    if N in Mat[ne]:
        print("POSSIBLE")
        exit()
print("IMPOSSIBLE")
