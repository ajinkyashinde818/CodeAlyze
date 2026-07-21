s=input()[::-1]
de=['maerd','esare']
dr='remaerd'
er='resare'
def check(a,x):
	if a > x:
		print("NO")
		exit(0)
i=0
n=len(s)
while i<n:
	check(i,n-5)
	if s[i:i+5] in de:
		i+=5
		continue
	check(i,n-6)
	if s[i:i+6] == er:
		i+=6
		continue
	check(i,n-7)
	if s[i:i+7]  == dr:
		i+=7
		continue
	print('NO')
	break
else:
	print("YES")
