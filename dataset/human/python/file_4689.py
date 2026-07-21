def mcxi2num (mcxi):
	changer = {"m":1000, "c":100, "x":10, "i":1}
	num = 0
	prefix = 1
	for s in mcxi:
		if s in "mcxi":
			num += prefix * changer[s]
			prefix = 1
		else :
			prefix = int(s)
	return num

def num2mcxi (num):
	changer = ["i", "x", "c", "m"]
	mcxi = ""
	numstr = str(num)
	length = len(numstr)
	for i in range(length):
		if numstr[i] == "0":
			pass
		elif numstr[i] == "1":
			mcxi += changer[length-i-1]
		else:
			mcxi += numstr[i] + changer[length-i-1]
	return mcxi

n = int(raw_input())
for i in range(n):
	s1, s2 = raw_input().split(" ")
	print num2mcxi(mcxi2num(s1) + mcxi2num(s2))
