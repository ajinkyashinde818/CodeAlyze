def pos(a, b, seq):
	st = set([a])
	for k in seq:
		new_st = set(st)
		for v in st:
			new_st.add(v%k)
		st = new_st
	return b in st
	
def main():
	n = input()
	aa = map(int, raw_input().split())
	bb = map(int, raw_input().split())
	def ok(seq):
		for a,b in zip(aa,bb):
			if not pos(a,b,seq):
				return False
		return True
	u = []
	for j in xrange(60,0,-1):
		if not ok(u + range(j-1,0,-1)):
			u.append(j)
	#print u
	if 59 in u:
		print -1
		return
	else:
		print sum(2**k for k in u)

main()
