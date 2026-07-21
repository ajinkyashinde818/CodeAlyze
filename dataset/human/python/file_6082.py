def solve(a, b, c):
	ret = 0

	for i in range(len(a)):
		ret += b[a[i]-1]

		if i != 0:
			if a[i] == a[i-1] + 1:
				ret += c[a[i-1]-1]

	return ret

def main():
	n = int(input())

	a = list(map(int, input().strip().split()))
	b = list(map(int, input().strip().split()))
	c = list(map(int, input().strip().split()))

	print (solve(a,b,c))

if __name__ == "__main__":
	main()
