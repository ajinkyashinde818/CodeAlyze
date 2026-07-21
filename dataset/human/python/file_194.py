import sys,random
try: sys.stdin = open('in.in','r')
except: pass

R,G,B,N = map(int,input().split())

ans = 0
for r in range(0,N+1,R):
	for b in range(0,N+1-r,B):
		if (N-b-r)%G != 0: continue
		ans += 1
print(ans)
