def main():
	s=input()
	X,Y=map(int,input().split())
	p=[]
	F=T=0
	if s[0]=="T":
		p.append(0)
	for i in range(len(s)):
		if s[i]=="F":
			if T:
				p.append(T)
			T=0
			F+=1
		else:
			if F:
				p.append(F)
			F=0
			T+=1
	p.append(max(F,T))
	a=[]
	b=[]
	now=0
	for i in range(len(p)//2):
		if now==0:
			a.append(p[i*2])
		else:
			b.append(p[i*2])
		if p[i*2+1]%2==1:
			if now==0:
				now=1
			else:
				now=0
	if len(p)%2==1:
		if now==0:
			a.append(p[-1])
		else:
			b.append(p[-1])
	dp1=[0]*(2*len(s)+1)
	dp2=[0]*(2*len(s)+1)
	dp1[len(s)]=1
	dp2[len(s)]=1
	first=0
	for x in a:
		dp1_copy=[0]*(2*len(s)+1)
		for i in range(2*len(s)+1):
			if i-x>=0:
				dp1_copy[i]=max(dp1[i-x],dp1_copy[i])
			if i+x<=2*len(s) and first:
				dp1_copy[i]=max(dp1[i+x],dp1_copy[i])
		dp1=dp1_copy.copy()
		first=1
	for x in b:
		dp2_copy=[0]*(2*len(s)+1)
		for i in range(2*len(s)+1):
			if i-x>=0:
				dp2_copy[i]=max(dp2[i-x],dp2_copy[i])
			if i+x<=2*len(s):
				dp2_copy[i]=max(dp2[i+x],dp2_copy[i])
		dp2=dp2_copy.copy()
	print("Yes" if dp1[len(s)+X] and dp2[len(s)+Y] else "No")
if __name__ == '__main__':
	main()
