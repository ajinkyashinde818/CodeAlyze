def myAnswer(K:int,N:int,A:list) -> int:
   distance=[]
   pre = A.pop(0)
   MIN = pre
   for a in A:
      distance.append(a - pre)
      pre = a
   distance.append(MIN + K - A[-1])
   distance.sort()
   return sum(distance[:N - 1])

def modelAnswer():
   tmp=1
def main():
   K,N = map(int,input().split())
   A = list(map(int,input().split()))
   print(myAnswer(K,N,A[:]))


if __name__ == '__main__':
   main()
