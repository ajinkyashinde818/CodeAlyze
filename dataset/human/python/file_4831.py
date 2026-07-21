from collections import defaultdict
from collections import deque
import itertools
import math

def readInt():
  return int(input())
def readInts():
  return list(map(int, input().split()))
def readChar():
  return input()
def readChars():
  return input().split()

def get():
  x = [ord(i) for i in list(input())]
  return x

s = sorted(get())
t = sorted(get(),reverse=True)
s.extend([0]*(len(t)-len(s)))
t.extend([0]*(len(s)-len(t)))

for i in range(len(s)):
  if s[i]==t[i]:
    continue
  elif s[i]<t[i]:
    print("Yes")
    exit()
  else:
    print("No")
    exit()
print("No")
