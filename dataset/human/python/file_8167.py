def myAnswer(K:int,S:int) -> int:
   ans = 0
   for x in range(K+1):
      for y in range(K+1):
        z = S - (x + y)
        if 0 <= z and z <= K:
           ans += 1
   return ans

def modelAnswer():
   return
def main():
   K,S = map(int,input().split())
   print(myAnswer(K,S))
if __name__ == '__main__':
   main()
