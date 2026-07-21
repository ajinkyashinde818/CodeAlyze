import re

def match(pattern, strings):
	return re.match('^{0}'.format(pattern), strings)

def any_match(strings):
	return re.match('^dream|^erase', strings)

S = input()

i = 0
while i < len(S):
	if match('dreamer', S[i:]):
		i += len('dreamer')
		if any_match(S[i:]):
			continue
		else:
			if i == len(S):
				break
			else:
				i -= len('dreamer')
				i += len('dream')
				continue
	elif match('eraser', S[i:]):
		i += len('eraser')
		if any_match(S[i:]):
			continue
		else:
			if i == len(S):
				break
			else:
				i -= len('eraser')
				i += len('erase')
				continue
	elif match('dream', S[i:]):
		i += len('dream')
		continue
	elif match('erase', S[i:]):
		i += len('erase')
		continue
	else:
		print('NO')
		exit()

print('YES')
