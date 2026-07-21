import collections
s=input()
q=int(input())
qv=[list(input().split()) for _ in range(q)]
cnt=0
ans=collections.deque()
for i in range(len(s)):
  ans.append(s[i])
for i in range(q):
  if qv[i][0]=="1":
    cnt+=1
  else:
    t,f,c = qv[i]
    if f=="1":
      if cnt%2==0:
        ans.appendleft(c)
      else:
        ans.append(c)
    elif f=="2":
      if cnt%2==0:
        ans.append(c)
      else:
        ans.appendleft(c)
if cnt%2!=0:
  ans.reverse()
print("".join(ans))
