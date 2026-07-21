a,b=map(int,input().split())
ListA = []
for i in range (a):
  ListA.append(input())
ListB = []
for i in range (b):
  ListB.append(input())
flag = False
  
def checkAB(List1,List2,aa,bb):
  for k in range(b):
    if List1[aa+k][bb:bb+b] != List2[k]:
      return False
  return True
  
for i in range(a-b+1):
  for j in range(a-b+1):
    if checkAB(ListA,ListB,i,j):
      flag = True
if flag:
  print("Yes")
else:
  print("No")
