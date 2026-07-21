from sys import stdin,stdout
Pi = lambda x: stdout.write(str(x) + '\n')
S = lambda x: x*(x+1) // 2
I = lambda x: 1+(2*x)
R = lambda:stdin.readline()
Ri = lambda x:map(int,x.split())
Rs = lambda x:map(str,x.split())
Rf = lambda x:map(float,x.split())
 
def main():	
	# t = int(R())
	for x in stdin:
		k,n = Ri(x)
		A = list(Ri(R()))
		ans = A[-1] - A[0]
		for i in range(n-1):
			ans = min(ans, (A[i]-A[0]) + (k-A[i+1]+A[0]))
			# Pi(ans)
		
		Pi(ans)

if __name__=='__main__':
	main()
