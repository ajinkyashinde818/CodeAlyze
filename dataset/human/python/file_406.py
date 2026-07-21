import collections

n = int(raw_input())
elems = map(int, raw_input().split(' '))
a = min(map(abs, elems))
s = sum(map(abs, elems))
count = 0
for c in elems:
	if c < 0: count +=1		
a = a if count % 2 else 0

print s - 2*a
"""
+++++----+++

obs 1
if the connected component has || even cardinality % 2==0


obs 2
if the connected component has odd cardinality I can reduce it to 1 
and move the - sign around 

obs 3
as I can move things around, I can merge ccs 


a = 0 if even number of negative signs else min([|v| for v in nums])
return sum([abs(v) for v in nums]) - a

"""
