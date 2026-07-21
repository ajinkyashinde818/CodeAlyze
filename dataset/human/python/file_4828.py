import sys
s=list(raw_input())
t=list(raw_input())
s.sort()
t.sort()
t.reverse()
N=len(s)
M=len(t)


for i in s:
	for j in t:
		if j==i:
			pass
		elif j>i:
			print "Yes"
			sys.exit()
		else:
			print "No"
			sys.exit()
else:
	if M>N:
		print "Yes"
	else:
		print "No"
