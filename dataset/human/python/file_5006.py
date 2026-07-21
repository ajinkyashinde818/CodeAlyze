import sys
patterns = [
	[1, 2, 1, 2, 1, 4, 1, 4],
	[1, 2, 1, 4, 1, 4, 1, 2],
	[1, 4, 1, 2, 1, 2, 1, 4],
	[1, 4, 1, 4, 1, 2, 1, 2],
	[2, 1, 2, 1, 4, 1, 4, 1],
	[2, 1, 4, 1, 4, 1, 2, 1],
	[4, 1, 2, 1, 2, 1, 4, 1],
	[4, 1, 4, 1, 2, 1, 2, 1],
]

while True:
	try:
		p = [int(x) for x in raw_input().split()]
		m = 999999999
		for ptn in patterns:
			rem = sum(max(0, v - x) for v, x in zip(ptn, p))
			if rem < m:
				m = rem
				pt = ptn
		print " ".join([str(x) for x in pt])
	except:
		break
