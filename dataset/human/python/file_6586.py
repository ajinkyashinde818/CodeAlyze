from collections import deque
S=input()
st="X"
Q=int(input())
q=[]
for _ in range(Q):
  q.append(input())#qは文字列のリストだよ
t=0#totalひっくり返し
for i in range(Q):
  if q[i]=="1":
    t+=1
  else:
    T,F,C=q[i].split()
    if F=="1" and t%2==0:
      st=C+st
    elif F=="2" and t%2==0:
      st=st+C
    elif F=="1" and t%2==1:
      st=st+C
    else:
      st=C+st
if t%2==0:
  print(st.replace("X",S))
else:
  print(st.replace("X",S)[::-1])
