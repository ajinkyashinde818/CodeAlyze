import sys

N,M = map(int, input().split())

strNs = []
strMs = []

for n in range(N):
	strNs.append(input())
	
for m in range(M):
	strMs.append(input())
	
def check_rest(start_row, start_col):
	for j in range(1,M):
		if strNs[start_row+j][start_col:start_col+M] != strMs[j]:
			return False
	else:
		return True
		

for i in range(N-M+1):
	tmp = strNs[i].find(strMs[0])
	while tmp >= 0:
		if check_rest(i, tmp):
			print("Yes")
			sys.exit()
		elif tmp + M > N:
			break
		else:
			tmp = strNs[i].find(strMs[0],tmp+1)
			
print("No")
