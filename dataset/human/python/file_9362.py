import sys
sys.setrecursionlimit(700000)

def s_in():
    return input()

def n_in():
    return int(input())

def l_in():
    return list(map(int, input().split()))

n,k=l_in()
A=l_in()

cnt=0
current = 0

memo={0: 0}

while cnt < k:
    n = A[current]-1
    cnt += 1

    if n in memo:
        delta = cnt - memo[n]

        p = (k-cnt)//delta
        cnt += p*delta
    else:
        memo[n] = cnt
    current = n
    
print(current+1)
