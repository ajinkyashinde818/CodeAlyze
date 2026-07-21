N,M = map(int,input().split())
ab_list = [tuple(map(int,input().split())) for _ in range(M)]

def check():
    halfways = [0 for _ in range(N)]
    for a,b in ab_list:
        if a==1:
            halfways[b] = 1
    for a,b in ab_list:
        if b==N:
            if halfways[a] == 1:
                return True
    return False

if check():
    print("POSSIBLE")
else:
    print("IMPOSSIBLE")
