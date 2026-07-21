def getIntList(inp):
	return [int(_) for _ in inp]


from sys import stdin
import sys
sys.setrecursionlimit(10**8)

def getInputs():
	inputs=[]
	for line in stdin:
		line=line.split()
		inputs.append(line)
	return inputs

def main(inputs):
	k,n=getIntList(inputs[0])
	aList=getIntList(inputs[1])
	
	d=k-aList[n-1]+aList[0]
	di=n-1
# 	print(d,di)
	for ai in range(n-1):
		dd=aList[ai+1]-aList[ai]
# 		print(dd)
		if dd>d:
			di=ai
			d=dd
	
	print(k-d)


if __name__=="__main__":
	inputs=getInputs()
# 	inputs=simInputs()
	main(inputs)
