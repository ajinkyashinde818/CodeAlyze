import sys
s=0
S=str(input())
while len(S)>=0:
  if s==len(S):
    print("YES")
    sys.exit()
  if S[s:s+5]=="dream":
    if len(S)==s+5:
      print("YES")
      sys.exit()
    elif S[s+5]=="d" or S[s+5:s+8]=="era":
      s+=5
    elif S[s+5:s+8]=="erd" or S[s+5:s+8]=="ere":
      s+=7
    elif S[s+5:s+7]=="er" and len(S)==s+7:
      print("YES")
      sys.exit()
    else: 
      print("NO")
      sys.exit()
  elif S[s:s+5]=="erase":
    if len(S)==s+5:
      print("YES")
      sys.exit()
    elif S[s+5]=="d" or S[s+5]=="e":
      s+=5
    elif S[s+5]=="r":
      s+=6
    else: 
      print("NO")
      sys.exit()
  else: 
    print("NO")
    sys.exit()
