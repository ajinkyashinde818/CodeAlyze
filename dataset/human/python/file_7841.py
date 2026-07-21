def main():
  N,K,S=map(int,input().split())
  MAX=10**9
  ans=[]
  if S!=MAX:
    for i in range(K):
      ans.append(str(S))
    for i in range(K,N):
      ans.append(str(MAX))
  else:
    for i in range(K):
      ans.append(str(S))
    for i in range(K,N):
      ans.append(str(MAX-1))
  print(" ".join(ans))
main()
