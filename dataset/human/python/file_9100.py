s = raw_input()
def solve(s):
	n = len(s)
	states = [[0, 0]]
	while len(states) > 0:
		state, i = states.pop()
		if i > n:
			print "what"
			continue
		if i == n:
			return "YES"
		if state == 1:
			if n - i >= 2 and s[i: i+2] == "er":
				states.append([0, i+2])
		if state == 2:
			if n - i >= 1 and s[i:i+1] == "r":
				states.append([0, i+1])
		if n - i >= 5:
			cs = s[i: i + 5]
			if cs == "dream":
				states.append([1, i+5])
			elif cs == "erase":
				states.append([2, i+5])
	return "NO"
 
print solve(s)
