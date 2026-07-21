import sys
S=raw_input()
judge=["dream","dreamer","erase","eraser"]

V=set()
V.add(0)

cnt=0
while cnt<len(S):
	tmp=set()
	for i in V:
		for j in judge:
			if S[i:i+7].find(j)==0:
				tmp.add(i+len(j))
				if i+len(j)==len(S):
					print "YES"
					sys.exit()
	V=tmp
	cnt+=1
else:
	print "NO"
