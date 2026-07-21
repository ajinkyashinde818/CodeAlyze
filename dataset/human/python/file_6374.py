import sys
sys.setrecursionlimit(10**6)
if sys.platform in (['ios','darwin','win32']):
	sys.stdin=open('Untitled.txt')
input = sys.stdin.readline
def INT(): return int(input())
def MAP(): return [int(s) for s in input().split()]

def main():
	N = INT()
	if N % 2:
		print(0)
	else:
		fives = 0
		for i in range(1, 27):
			if N//2 >= 5**i:
				fives += (N//2)//(5**i)
		print(fives)

if __name__ == '__main__':
	main()
