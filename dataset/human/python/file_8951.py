def main():
	S = input()
	pattern_exist = True
	while S:
		if S.startswith("dreamer"):
			if len(S) == 7:
				break
			if S[7:].startswith("dream") or S[7:].startswith("erase"):
				S = S[7:]
				continue
		if S.startswith("dream"):
			S = S[5:]
			continue
		if S.startswith("eraser"):
			if len(S) == 6:
				break
			if S[6:].startswith("dream") or S[6:].startswith("erase"):
				S = S[6:]
				continue
		if S.startswith("erase"):
			S = S[5:]
			continue
		pattern_exist = False
		break
	if pattern_exist:
		print("YES")
	else:
		print("NO")


if __name__ == '__main__':
	main()
