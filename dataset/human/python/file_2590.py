D,G = map(int,input().split())
PC = [list(map(int,input().split())) for i in range(D)]

def up_f(i,score):
	if i == D+1:
		return 10**9
	n = min(score//(i*100),PC[i-1][0])
	s = n*100*i
	s += PC[i-1][1] if n == PC[i-1][0] else 0
	if s < score:
		n += up_f(i+1,score-s)
	return min(n,up_f(i+1,score))

def down_f(i,score):
	if i == 0:
		return 10**9
	n = min(score//(i*100),PC[i-1][0])
	s = n*100*i
	s += PC[i-1][1] if n == PC[i-1][0] else 0
	if s < score:
		n += down_f(i-1,score-s)
	return min(n,down_f(i-1,score))

print(min(up_f(1,G),down_f(D,G)))
