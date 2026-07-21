import string
lisL = list(string.ascii_lowercase)
dic = dict(zip(lisL,list(range(26))))
s = input()
t = input()
lisT = list(reversed(sorted(t)))
lisS = list(sorted(s))
for sitem,titem in zip(lisS[0:min( len(lisT),len(lisS) )],lisT[0:min( len(lisT),len(lisS) )]):
  if dic[sitem] < dic[titem]:
    print ("Yes")
    break
  elif dic[sitem] > dic[titem]:
    print ("No")
    break
else:
  if len(lisT) > len(lisS):
    print ("Yes")
  else:
    print ("No")
