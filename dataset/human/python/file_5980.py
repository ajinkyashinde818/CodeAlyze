N = int(input())
A = list(map(int, input().split(" ")))
B = list(map(int,input().split(" ")))
C = list(map(int,input().split(" ")))

def wei(N,A,B,C):
    r = 0
    c = 0
    C.insert(0,0)
    for i in A:
        r+=B[i-1]
        if i - c == 1:
            c = 1
            r+=C[i-1]
        c = i
    return r

print(wei(N,A,B,C))
