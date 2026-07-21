import sys
sys.setrecursionlimit(2000)

D, goal = map(int, input().split())
q_num, bonus = [], []
for i in range(1,D+1):
  q, b = map(int, input().split())
  q_num.append(q)
  bonus.append(b)
ans = 100000

def rec2(current_qn, next_n, current_score, tyuuto_done):
  if next_n == D + 1:
    global ans
    if current_score >= goal:
      ans = min(ans, current_qn)
  else:
    rec2(current_qn+q_num[next_n-1], next_n+1, current_score+q_num[next_n-1]*next_n*100+bonus[next_n-1], tyuuto_done)
    rec2(current_qn, next_n+1, current_score, tyuuto_done)
    if not tyuuto_done:
      for i in range(1,q_num[next_n-1]):
        rec2(current_qn+i, next_n+1, current_score+i*next_n*100, 1)

def rec(comb, next_n, current_score):
  if next_n == D + 1:
    global ans
    if current_score >= goal:
      ans = min(ans, sum(comb))
  else:
    for i in range(q_num[next_n-1]):
      rec(comb + [i], next_n+1, current_score + i * next_n * 100)
    rec(comb + [q_num[next_n-1]], next_n+1, current_score + q_num[next_n-1] * next_n * 100 + bonus[next_n-1])

# rec([], 1, 0)
rec2(0, 1, 0, 0)

print(ans)
