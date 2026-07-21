n=int(input())
a_n=list(map(int,input().split()))
count=0
ans=0
for i in a_n:
  if i <0:
    count +=1

def fun():
  tmp_ans=0
  for i in a_n:
    if i<0:
      tmp_ans += -1*i
    else:
      tmp_ans += i
  return tmp_ans

if count%2==0:
  ans = fun()
else:
  tmp=abs(a_n[0])
  for i in a_n:
    if tmp > abs(i):
      tmp = abs(i)
  
  ans =fun()-2*tmp
print(ans)
