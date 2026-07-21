import sys

if sys.platform =='ios':
	sys.stdin=open('Untitled.txt')
input = sys.stdin.readline
def INT(): return int(input())
def MAP(): return [int(s) for s in input().split()]

T = ['dream', 'dreamer', 'erase', 'eraser']

S = input().rstrip()
S = S[::-1]
#print(S)

cur = 0
while cur < len(S):
	#print(cur, S[cur:])
	for t in T:
		#print(S[cur:cur+len(t)], t[::-1])
		if S[cur:cur+len(t)] == t[::-1]:
			cur += len(t)
			break
	else:
		print('NO')
		break
else:
	print('YES')
