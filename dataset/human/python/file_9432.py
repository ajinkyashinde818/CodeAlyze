import sys 
try:
	sys.stdin = open('Input.txt', 'r') 
	sys.stdout = open('Output.txt', 'w')
except:
	pass

input = sys.stdin.readline

n,k = map(int,input().split())
l = list(map(int,input().split()))
l.insert(0,0)
# print(l)
d = {}
city = 1
turn = 0
ini = []
cnt = 0
while True:
	if d.get(city) == None:
		d[city] = turn
		turn += 1
		ini.append(city)
		city = l[city]
		# print(city,d)

	else:
		cnt = d[city] - 1
		# print(cnt)
		rep = turn - d[city]
		# print(rep)
		break

if k<=cnt:
	print(ini[k])
else:
	# print(ini)
	# print(((k-cnt-1)%rep))
	print(ini[cnt+1+((k-cnt-1)%rep)])
