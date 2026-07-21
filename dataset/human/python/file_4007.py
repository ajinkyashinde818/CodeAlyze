from collections import defaultdict
from collections import OrderedDict
from collections import deque
from itertools import combinations
from itertools import permutations
import bisect,math,heapq
alphabet = "abcdefghijklmnopqrstuvwxyz"


def primeFactors(n):
	count = defaultdict(int)
	while n % 2 == 0: 
		count[2]+=1 
		n = n / 2 
	for i in range(3,int(math.sqrt(n))+1,2): 
		while n % i== 0: 
			count[i]+=1
			n = n / i 
	if n > 2: 
		count[n]+=1
	return count


n = int(input())
c = primeFactors(n)
ans = 0
for k,v in c.items():
	ans += (-1 + (1+8*v)**0.5)//2
print(int(ans))
