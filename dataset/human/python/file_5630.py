'''
Created on 2020/09/02

@author: harurun
'''
def main():
  import sys
  pin=sys.stdin.readline
  pout=sys.stdout.write
  perr=sys.stderr.write
  
  s=list(pin()[:-1])
  
  cnt=0
  while s:
    if len(s)==1:
      break
    elif s[0]==s[-1]:
      s.pop(0)
      s.pop(-1)
    else:
      if s[0]!='x' and s[-1]!='x':
        print(-1)
        return 
      else:
        if s[0]=='x':
          s.pop(0)
        else:
          s.pop(-1)
        cnt+=1
  print(cnt)
  return 
main()
