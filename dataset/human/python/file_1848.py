N,M = map(int,input().split())
A = [input() for i in range(N)]
B = [input() for i in range(M)]

def match(ofs_x, ofs_y):
    for ar,br in zip(A[ofs_y:], B):
        if ar[ofs_x : ofs_x + M] != br:
            return False
    return True

for y in range(N-M+1):
    for x in range(N-M+1):
        if match(x,y):
            print('Yes')
            exit()
print('No')
