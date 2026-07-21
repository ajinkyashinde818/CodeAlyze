import sys
n=input()
a=map(int, raw_input().split())
diff=[a[(i+1)%n]-a[i] for i in range(n)]
cnt=max(diff)
diff=[value-cnt for value in diff]
start=[]
for value in diff:
	if value%n:
		print "NO"
		exit()
	else:
		start.append(-value/n)
cnt=sum(start)
b=[0]
for i in range(n):
	b[0]+=start[i]*(n-i)
for i in range(n):
	b.append(b[-1]+cnt-start[i]*n)
assert b[0]==b[-1]
b=b[:-1]
for i in range(n):
	if (a[i]-b[i])%(n*(n+1)/2) or a[i]<b[i]:
		print "NO"
		exit()
print "YES"
