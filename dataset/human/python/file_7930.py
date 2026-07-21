s = input()
k=0
rei=['a','b','c']
def counter(v):
	a=0
	for i in list(s):
		if i == v:
			a+=1
	return a
result=0
for i in rei:
	if counter(i) == 1:
		result+=1
if result == 3:
	print("Yes")
else:
	print("No")
