from collections import defaultdict

def main():
    N, K = map(int, input().split())
    A = list(map(int, input().split()))

    town = defaultdict(int)
    cn = defaultdict(int)
    
    visited = set()
    visited.add(0)
    cnt = 0
    tmp = A[0]-1
    town[cnt] = 0
    ii = 0
    
    while True:
        if(tmp not in visited):
            visited.add(tmp)
            cnt += 1
            cn[tmp] = cnt
            town[cnt] = tmp
            tmp = A[tmp]-1
        else:
            ii = cn[tmp]
            break
    
    if(K >= len(town)):
        if(ii != 0):
            K -= ii
            ans = town[(K%(len(town)-ii))+ii]+1
        else:    
            ans = town[K%(len(town))]+1
        print(ans)
    else:
        ans = town[K]+1
        print(ans)
main()
