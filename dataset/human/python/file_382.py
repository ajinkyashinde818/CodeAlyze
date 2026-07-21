import sys

if sys.platform =='ios':
	sys.stdin=open('Untitled.txt')
input = sys.stdin.readline
def INT(): return int(input())
def MAP(): return [int(s) for s in input().split()]

N = INT()
A = MAP()

B = [abs(a) for a in A]
negatives = sum([1 for a in A if a<0])

#print(B, negatives)

if negatives % 2:
	min_B = min(B)
	ans = sum(B) - (2*min_B)
else:
	ans = sum(B)

print(ans)
