def main():
  S = input()
  Q = int(input())
  import sys
  que = [list(sys.stdin.readline().split()) for _ in range(Q)]
  pre=''
  post=''
  judge = False
  for l in que:
    if int(l[0])==1:
      if judge:
        judge = False
      else:
        judge = True

    elif int(l[0])==2:
      f,c = int(l[1]),l[2]
      if judge:
        if f==1:
          f=2
        elif f==2:
          f=1
      if f==1:
        pre = ''.join([pre,c])
      elif f==2:
        post = ''.join([post,c])

  pre = pre[::-1]
  S = pre+S+post
  if judge:
    S=S[::-1]
  print(S)
  
main()
