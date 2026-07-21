from collections import deque
alfabet=deque(input())
n=int(input())
reverse=0
for i in range(n):
  operation_list=list(input().split())
  if int(operation_list[0])==1:
    reverse+=1
  else:
    if int(operation_list[1])==2 and reverse%2==0:
      alfabet.append(operation_list[2])
    elif int(operation_list[1])==2 and reverse%2==1:
      alfabet.appendleft(operation_list[2])
    elif int(operation_list[1])==1 and reverse%2==0:
      alfabet.appendleft(operation_list[2])
    elif int(operation_list[1])==1 and reverse%2==1:
      alfabet.append(operation_list[2])
if reverse%2!=0:
  alfabet.reverse()
print(''.join(alfabet))
