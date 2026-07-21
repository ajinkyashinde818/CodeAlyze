def myAnswer(N:int,M:int,A:list,B:list) -> int:
   dic = {key:[] for key in range(1,N+1)}
   for a,b in zip(A,B):
      dic[a].append(b)
   for i in dic[1]:
      for value in dic[i]:
         if(N == value):
            return "POSSIBLE"
   else:
      return "IMPOSSIBLE"

def modelAnswer():
   return
def main():
   N,M = map(int,input().split())
   A = []
   B = []
   for _ in range(M):
      a,b = map(int,input().split())
      A.append(a)
      B.append(b)
   print(myAnswer(N,M,A[:],B[:]))
if __name__ == '__main__':
   main()
