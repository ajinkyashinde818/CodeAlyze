def equal(A,B,i,j):
	ret = True
	for row in xrange(i,i+len(B)):
		if A[row][j:j+len(B)] != B[row-i]:
			ret = False
	return ret

n,m = map(int,raw_input().split())
A = []
B = []
for i in xrange(n):
	A.append(raw_input())
for i in xrange(m):
	B.append(raw_input())


contained = False
for i in xrange(n-m+1):
	for j in xrange(n-m+1):
		if equal(A,B,i,j):
			contained = True
			break
		else:
		 	pass
	if contained: break

if contained: print 'Yes'
else: print 'No'
