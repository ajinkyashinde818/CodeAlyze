import sys
readline=sys.stdin.buffer.readline
K, N = map(int, readline().rstrip().split())
s= readline().rstrip().split()
max = 0
for i in range(N):
    if i == N-1:
        if max <  (int(s[0])+K) - int(s[i]):
            max = (int(s[0])+K) - int(s[i])
    else: 
        if max <  int(s[i+1])-int(s[i]):
            max = int(s[i+1])-int(s[i])

print(K-max)
