import sys, math
sys.setrecursionlimit(10**6)

def b(n):
	i = 1
	while(True):
		if i * (i+1) == n*2:
			return i
		elif i * (i+1) > n*2:
			return 0
		else:
			i += 1

def main():
	n = int(input())
	ref = b(n)
	if ref == 0:
		print("No")
	else:
		print("Yes")
		s = [[] for i in range(ref+1)]
		k = 1
		for i in range(ref):
			for j in range(i+1,ref+1):
				s[i] += [k]
				s[j] += [k]
				k+=1
		print(ref + 1)
		for i in range(ref+1):
			print(str(ref) + " " + " ".join(map(str,s[i])))
	return

main()
