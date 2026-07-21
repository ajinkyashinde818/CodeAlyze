import sys 
S = input()
A = []
for i,s in enumerate(S):
    if s != 'x':  A.append(i)
if not A:
    print(0)
    sys.exit()
for i in range(len(A)//2):
    if S[A[i]] != S[A[-i-1]]:
        print(-1)
        sys.exit()
ans = abs((len(S)-1-A[-1])-A[0])
for i in range(len(A)//2):
    cnt = abs(A[i+1]-A[i] - (A[-1-i]-A[-2-i]))
    ans += cnt
print(ans)
