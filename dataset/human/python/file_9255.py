import re

def solve(s):
	s=re.sub('eraser','',s)
	s=re.sub('erase','',s)
	s=re.sub('dreamer','',s)
	s=re.sub('dream','',s)
	if s:
		return 'NO'
	else:
		return 'YES'

s=input()
print(solve(s))
