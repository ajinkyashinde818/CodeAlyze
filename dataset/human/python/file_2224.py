D,G=map(int,input().split())
answer=0
Q=[]
for i in range(D):
  p,c=map(int,input().split())
  answer+=p
  Q.append((i+1,p,c))
dp=[-10]*(answer+1)

dp[0]=0
for i,p,c in Q:
  for j in range(answer,-1,-1):
    for k in range(1,p+1):
      if k==p:
        cc=i*100*k+c
      else:
        cc=i*100*k
      if j-k>=0:
        dp[j]=max(dp[j],dp[j-k]+cc)
        
for i in range(answer+1):
  if dp[i]>=G:
    print(i)
    break

'''
from operator import itemgetter
import copy

D,G=map(int,input().split())

score=[]
scoreBonus=[]

answer=0
answerscore=G

for i in range(D):
  score.append(list(map(int,input().split())))
  scoreBonus.append([(i+1)*100,(i+1)*100,score[i][0],score[i][0]*(i+1)*100+score[i][1],0])
  
Bonus=copy.deepcopy(scoreBonus)
print(Bonus)



while(answerscore>0):
  Deletescore=[]
  
  
  
  for i in range(len(scoreBonus)):
    if scoreBonus[i][1]*scoreBonus[i][2]<=answerscore:
      scoreBonus[i][0]=(score[i][0]*(i+1)*100+score[i][1])//(score[i][0])
      scoreBonus[i][4]=1
    if scoreBonus[i][1]*scoreBonus[i][2]>answerscore:
      scoreBonus[i][0]=scoreBonus[i][1]
      scoreBonus[i][4]=0
    answerscore-=scoreBonus[i][3]
    answer+=scoreBonus[i][2]
    Deletescore.append(i)
  scoreBonus.sort(reverse=True)

  print(scoreBonus)
  print(Bonus)

  for i in range(len(scoreBonus)):
    count=scoreBonus[i][2]
    if scoreBonus[i][4]==1:
      answerscore-=scoreBonus[i][3]
      answer+=scoreBonus[i][2]
      count=0
      Deletescore.append(i)
      break;
    while(answerscore>0 and count!=0):
      answerscore-=scoreBonus[i][1]
      print(answerscore)
      answer+=1
      count-=1
    if answerscore<=0:
      print(answer)
      exit() 
  print(Deletescore)
  del scoreBonus[Deletescore[i]]
  print(scoreBonus)

print(answer)
print(scoreBonus)
if answerscore<=0:
  print(answer)
  exit()
  


scoreR=sorted(scoreBonus, key=itemgetter(1),reverse=True)
print(scoreR)
'''
