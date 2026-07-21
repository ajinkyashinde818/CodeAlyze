import sys
sys.setrecursionlimit(10**6)

def toord(st):
	ans = ""
	if st//1000 != 0:
		if st // 1000 != 1:
			ans += str(st//1000)
		ans+="m"
		st = st % 1000
	if st // 100 != 0:
		if st // 100 != 1:
			ans += str(st//100)
		ans += "c"
		st = st % 100
	if st // 10 != 0:
		if st // 10 != 1:
			ans += str(st//10)
		ans += "x"
		st = st % 10
	if st != 0:
		if st!=1:
			ans += str(st)
		ans += "i"
	return ans
			

def main():
	a,b = input().split()
	a, b = "+" + a, "+"+b
	a, b = a.replace("m","*m+"), b.replace("m", "*m+")
	a, b = a.replace("c","*c+"), b.replace("c", "*c+")
	a, b = a.replace("x","*x+"), b.replace("x", "*x+")
	a, b = a.replace("i","*i+"), b.replace("i", "*i")
	ans, tans = 0, 0
	for j in a+b:
		# print(j,end="")
		if j == "+":
			tans = 1
		elif j == "*":
			ans = ans
		elif j == "m":
			tans *= 1000
			ans += tans
		elif j == "c":
			tans *= 100
			ans += tans
		elif j == "x":
			tans *= 10
			ans += tans
		elif j == "i":
			ans += tans			
		else:
			tans = int(j)
	print(toord(ans))
	return

n = int(input())
for i in range(n):
	main()
