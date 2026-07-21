def main():
	s = str(input())
	q = int(input())
	shiji = 1
	rcount = 0
	from collections import deque
	s = deque(s)
	for i in range(q):
		qu = list(map(str,input().split()))
		if qu[0] != '1':
			if shiji == 1:
				if qu[1] == '1':
					s.appendleft(qu[2])
				else:
					s.append(qu[2])
			else:
				if qu[1] == '2':
					s.appendleft(qu[2])
				else:
					s.append(qu[2])
		else:
			shiji *= -1
			rcount += 1
	if rcount % 2 == 0:
		print(''.join(map(str,s)))
	else:
		s.reverse()
		print(''.join(map(str,s)))

if __name__ == '__main__':
	main()
