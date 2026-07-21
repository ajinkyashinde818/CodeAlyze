def main():
	S=input()                                               # 1行1列
	Q=int(input())                                          # 1行1列
	Q_LIST=[input().split() for i in range(Q)]                # N行C列・・・Cは任意
	 
	dir = 0 # 0が正常

	S_HEAD = ''
	S_BACK = ''

	for query in Q_LIST:
		if query[0] == '1':
			if dir == 0:
				dir = 1
			else:
				dir = 0
	 
		if dir == 0:
			HEAD = '1'
			BACK = '2'
		else:
			HEAD = '2'
			BACK = '1'
	 
		if query[0] == '2':
			if query[1] == HEAD:
				S_HEAD = query[2] + S_HEAD
			if query[1] == BACK:
				S_BACK =  S_BACK + query[2]

	S = S_HEAD + S + S_BACK

	if dir == 0:
		print(S)
	else:
		print(S[::-1])

if __name__ == '__main__':
    main()
