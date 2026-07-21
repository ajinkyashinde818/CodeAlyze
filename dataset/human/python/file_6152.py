def main():
	cookie = 0
	A,B,C = map(int,input().split())

	if C > B :
		C -= B
		cookie += (B*2)
		if C > A :
			cookie += (A+1)
		elif C <= A:
			cookie += C
		return cookie
	elif C <= B :
		return B+C

if __name__ == "__main__" :
	print(main())
