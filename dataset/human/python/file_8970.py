s=input()
l=len(s)
def judge():
  cnt=0
  while True:
    if s[l-cnt-6:l-cnt]=='eraser':
      cnt+=6
    elif s[l-cnt-5:l-cnt]=='erase':
      cnt+=5
    elif s[l-cnt-7:l-cnt]=='dreamer':
      cnt+=7
    elif s[l-cnt-5:l-cnt]=='dream':
      cnt+=5
    else:
      print('NO')
      exit()
    if cnt==len(s):
      print('YES')
      exit()

judge()
