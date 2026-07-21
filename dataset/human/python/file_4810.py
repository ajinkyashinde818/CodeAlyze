import sys

def main():
  s = list(input())
  t = list(input())
  
  s.sort()
  t.sort()
  t.reverse()
  m = min(len(s), len(t))
  for i in range(m):
    if s[i] > t[i]:
      print('No')
      sys.exit()
    elif s[i] < t[i]:
      print('Yes')
      sys.exit()

  if len(s) < len(t):
    print('Yes')
    sys.exit()
  else:
    print('No')
    sys.exit()
    
main()
