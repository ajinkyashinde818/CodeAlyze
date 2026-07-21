import sys
import re

N = sys.stdin.readline() 
A = (sys.stdin.readline()).split()
B = (sys.stdin.readline()).split()
C = (sys.stdin.readline()).split()

j=0
result = 0

for i in A:
  i = int(i)
  result += int(B[i-1])
  
  if j != 0 and j+1 is i:
    result += int(C[j-1])
  j = i
  

print (result)
