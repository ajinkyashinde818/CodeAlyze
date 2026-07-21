def modelAnswer(N:int,K:int,S:int) -> None:
   ans = "{} ".format(S)*K
   if(S == 10**9):
      ans += "1 "*(N-K)
   else:
      ans += "{} ".format(S+1)*(N-K)
   print(ans)
def main():
   N,K,S = map(int,input().split())
   modelAnswer(N,K,S)
if __name__ == '__main__':
   main()
