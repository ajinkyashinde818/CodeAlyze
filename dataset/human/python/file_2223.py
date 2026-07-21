import collections

d,g =  map(int, raw_input().split())
cc = {0:0}
picis = [map(int,raw_input().split()) for _ in range(d)]

pisum = sum([pi for pi,ci in picis] or [0])
for i in range(len(picis)):
	pi,ci = picis[i]
	for p in range(1, pisum + 1)[::-1]:
		for q in range(1, pi + 1):
			if p - q >= 0 and (p - q) in cc:
				cc[p] = max(cc[p] if p in cc else -float('inf'),  cc[p - q] + (100 * q * (i + 1)) + (ci if pi == q else 0))

for k in range(pisum+1):
	if cc[k] >= g:
		print k
		break
