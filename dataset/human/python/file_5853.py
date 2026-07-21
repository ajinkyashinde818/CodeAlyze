import sys

N=int(sys.stdin.readline().rstrip())
AList=list(map(int,sys.stdin.readline().split()))
BList=list(map(int,sys.stdin.readline().split()))
CList=list(map(int,sys.stdin.readline().split()))

beforeBuffet=-1
sutisfier=0
for i in range(N):
  buffet=AList[i]
  sutisfier+=BList[buffet-1]
  if buffet-beforeBuffet==1:
    sutisfier+=CList[buffet-2]
  beforeBuffet=buffet
print(sutisfier)
