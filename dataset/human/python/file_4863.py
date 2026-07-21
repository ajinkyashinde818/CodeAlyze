s = input()
t = input()


d ={chr(i):i for i in range(97, 97+26)}

s = [d[i]for i in s]
t = [d[i]for i in t]

def check(s,t):
  if (len(s) == 0 )& (len(t)>0) :
    return 'Yes'
  elif (len(t) == 0 )& (len(s)>=0) :
    return 'No'
  a,b = min(s), max(t)
  if a< b:
    return 'Yes'
  elif a==b :
    return a
  else :
    return 'No'
    
while True :
  x = check(s,t)
  if type(x)== int :
    s.remove(x)
    t.remove(x)
  else :
    break
print(x)
