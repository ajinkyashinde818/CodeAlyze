def check(str):
	for i in range(len(str)//5+1):
		if str=="":
			return "YES"
		elif str[-5:]=="dream" or str[-5:]=="erase" :
			str=str[:-5]
		elif str[-6:]=="eraser":
			str=str[:-6]
		elif str[-7:]=="dreamer":
			str=str[:-7]
		else:
			return "NO"

str=input()
print(check(str))
