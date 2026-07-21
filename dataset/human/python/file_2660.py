def makebit(n, d):
	lst = []
	m = n
	for i in range(0, d):
		lst.append(m%2==1)
		m = m / 2
	return lst
D, G = map(int, raw_input().split())
plist = []
clist = []
for i in range(0, D):
	p, c = map(int, raw_input().split())
	plist.append(p)
	clist.append(c)
n = 1
for i in range(0, D):
	n = n * 2
lst = []
for i in range(0, n):
	lst.append(makebit(i, D))
min = 10000
for i in range(0, n):
	sum = 0
	cnt = 0
	for j in range(0, D):
		if lst[i][j]:
			sum += (j+1)*100*plist[j] + clist[j]
			cnt += plist[j]
	for j in range(0, D):
		if not lst[i][-1-j]:
			if sum + (D-j)*100*(plist[-1-j]-1) < G:
				sum += (D-j)*100*(plist[-1-j]-1)
				cnt += plist[-1-j] - 1
			elif sum < G:
				for k in range(0, plist[-1-j]-1):
					sum += (D-j)*100
					cnt += 1
					if G <= sum: break
		if G <= sum: break
	if cnt < min and G <= sum:
		min = cnt
print min
