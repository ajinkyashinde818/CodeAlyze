def abc104():

	p,c=[],[]
	D,G=map(int,input().split())
	for i in range(D):
		P,C=map(int,input().split())
		p.append(P)
		c.append(C)


	def saisho(a,b):
		if a==0:
			return 10**10
		m=min(b//(a*100),p[a-1])
		s=100*a*m
		if m==p[a-1]:
			s+=c[a-1]
		if s<b:
			m+=saisho(a-1,b-s)
		return min(m,saisho(a-1,b))
	
	print(saisho(D,G))
	
abc104()
