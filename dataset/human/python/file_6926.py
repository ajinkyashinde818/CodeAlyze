import sys
s = input()
flag = 0
s1 = ""
s2 = ""

for i in range(int(input())):
	X = sys.stdin.readline().split()
	if int(X[0]) == 1:
		flag = flag^1	
	elif (int(X[1])-1)^flag == 0:
		s1 += X[2]
	else:
		s2 += X[2]
s3 = s1[::-1]+s+s2
if flag:
	print(s3[::-1])
else:
	print(s3)
