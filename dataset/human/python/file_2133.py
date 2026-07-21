from collections import Counter
from functools import reduce
 
def counter(list_1):
	return ((reduce(lambda a,b:a*b,map(lambda x:x+1,list_1))-1)%(10**9+7))
  
N=input()
S=input()
answer=counter(Counter(S).values())
print(answer)
