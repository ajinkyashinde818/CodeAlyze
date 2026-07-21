def i1():
 return int(input())
def i2():
 return [int(i) for i in input().split()]
s=input()
ss=s.replace("x","")
if ss!=ss[::-1]:
 print(-1)
else:
 e=[]
 for i in range(len(ss)):
  e.append(ss[i])
 j=0
 k=0
 d1=[]
 jj=0
 kk=0
 d2=[]
 sr=s[::-1]
 for i in range(len(s)):
  if k<len(e) and s[i]==e[k] :
    d1.append(s[j:i])
    j=i+1
    k+=1
  if kk<len(e) and sr[i]==e[kk] :
    d2.append(sr[jj:i])
    jj=i+1
    kk+=1
 d1.append(s[j:])
 d2.append(sr[jj:]) 
 dd=0  
 for i in range(len(d1)//2):
   dd+=abs(len(d1[i])-len(d2[i]))
 print(dd)
