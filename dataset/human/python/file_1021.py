import sys
def input():
	return sys.stdin.readline().strip()

N = int(input())
S = list(input())

LR = ['L', 'R']
if S[0] != "B" or S[-1] != "B":
	print(0)
	exit()
x = [0]
for i in range(1, 2*N):
	if S[i] == S[i - 1]:
		x.append(x[-1]^1)
	else:
		x.append(x[-1])

if x[-1] != 1:
	print(0)
	exit()
if sum(x) != N:
	print(0)
	exit()

L_sum = 0
total = 1
for i in range(0, 2*N):
	if x[i] == 0:
		L_sum += 1
	else:
		total *= L_sum
		L_sum -=1
		total = total % 1000000007

for i in range(N):
	total *= i + 1
	total = total % 1000000007

print(total)
