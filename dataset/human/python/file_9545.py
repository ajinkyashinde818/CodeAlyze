import sys
input = sys.stdin.readline

N, K = map(int, input().split())
A = list(map(int, input().split()))
l = [0]
s = {0}

for i in range(K):
    nex = A[l[-1]]-1
    
    if nex in s:
        for i in range(len(l)):
            if l[i]==nex:
                mark = i
                break
        
        t = len(l)-mark
        print(l[mark+(K-mark)%t]+1)
        exit()
    
    l.append(nex)
    s.add(nex)

print(nex+1)
