D, G = map(int,input().split())
PC = [list(map(int, input().split())) for _ in range(D)]
comp_ans_ll = [0 for _ in range(D) ]
n_ans=float("inf")

def main():
  global n_ans
  for i in range(1<<D):
    comp_ans_l = [0 for _ in range(D) ]
    score = 0
    tmp_n_ans = 0
    for j in range(D):
      if (i>>j)&1:
        score += (j+1)*100*PC[j][0] + PC[j][1]
        tmp_n_ans+=PC[j][0]
        comp_ans_l[j] = 1
    if G <= score:
      n_ans = min(n_ans, tmp_n_ans)
    else:
      for k in range(D-1,-1,-1):
        if comp_ans_l[k]==0:
          for l in range(1,PC[k][0]):
            score += 100*(k+1)
            tmp_n_ans+=1
            if G <= score:
              n_ans = min(n_ans, tmp_n_ans)
              break
        if score>=G:
          break
  print(n_ans)

if __name__=="__main__":
  main()
