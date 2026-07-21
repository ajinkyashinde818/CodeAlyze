from sys import stdin
N,M = [int(x) for x in stdin.readline().rstrip().split()]
A = []
for _ in range(N):
    A.append(list(input()))
    
B = []
for _ in range(M):
    B.append(list(input()))

for dh in range(0,N-M+1):
    for dw in range(0,N-M+1):
        ans = True
        for bh in range(0,M):
            for bw in range(0,M):
                if B[bh][bw] != A[bh+dh][bw+dw]:
                    ans = False
        if ans:
            print("Yes")
            break
    else:
      continue
    break
if ans == False:
    print("No")
