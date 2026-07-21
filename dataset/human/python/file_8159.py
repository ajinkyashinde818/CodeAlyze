import sys
sys.setrecursionlimit(10 ** 5)


readline =sys.stdin.readline

def process():
    k,s = map(int,readline().rstrip().split())
    cnt=0

    for i in range(0,k+1):
        for j in range(0,k+1):
            z = s-(i+j)
            if z>=0 and z<=k:
                cnt+=1
    
    return cnt


print(process())
