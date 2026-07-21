from collections import Counter
def myAnswer(N:int,S:list) -> int:
   counter = Counter(S)
   ans = 1
   for s in list(set(S)):
      ans *= counter[s] + 1

   return (ans - 1) % (10 ** 9 + 7)
def modelAnswer():
   return
def main():
   N = int(input())
   S = list(input())
   print(myAnswer(N,S))
if __name__ == '__main__':
   main()
