import collections
N=int(input())
A=[int(x) for x in input().split()]
B=[int(x) for x in input().split()]
C=A+B
if (max(collections.Counter(C).values()))<=N:
  judge="Yes"
  B=B[::-1]
  fore=0
  back=-1
  for i in range(len(A)):
    if A[i]==B[i]:
      dup=A[i]
      if A[fore]!=dup and B[fore]!=dup:
        B[fore],B[i]=B[i],B[fore]
        fore+=1
      elif A[back]!=dup and B[back]!=dup:
        B[back],B[i]=B[i],B[back]
        back-=1
      else:
        judge="No"
else:
  judge="No"
if judge=="Yes":
  print(judge)
  print(' '.join(map(str, B)))
else:
  print(judge)
