import numpy as np
import sys

if __name__=="__main__":
   N, M = list(map(int, input().replace("\n","").split(" ")))
   a = [list(map(int, list(input().replace("\n","").replace(".", "1").replace("#", "0")))) for i in range(N)]
   a = np.array(a)
   b = [list(map(int, list(input().replace("\n","").replace(".", "1").replace("#", "0")))) for i in range(M)]
   b = np.array(b)


   for i in range(N - M + 1):
       for j in	range(N - M + 1):
           if((a[i:i+M,j:j+M] == b).all()):
               print("Yes")
               sys.exit(0)
   print("No")
