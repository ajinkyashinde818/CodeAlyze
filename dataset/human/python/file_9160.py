dbflag=""

def debug(*args):
	if ""!=dbflag: print(*args)

if ""!=dbflag: _INDATA=open(dbflag)

def readline():
	if ""!=dbflag:return _INDATA.readline()
	else: return input()


result = -1

S = readline().rstrip()

import re
#pat = re.compile(pattern)
#pat.match(content)
ismatch = re.match(r'^(dream|dreamer|erase|eraser)*$',S)

if ismatch:
	result = "YES"
else:
	result = "NO"

print(result)
