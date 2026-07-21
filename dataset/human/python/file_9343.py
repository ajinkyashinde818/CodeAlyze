import sys
import numpy as np

read = sys.stdin.buffer.read
readline = sys.stdin.buffer.readline
readlines = sys.stdin.buffer.readlines

N,K = map(int, readline().split())
A = np.int32(read().split())

A -= 1

def mult(A, B):
  return B[A]

def power(A, n):
  if not n:
    return np.arange(N)
  B = power(A, n//2)
  B = mult(B,B)
  return mult(A,B) if n & 1 else B

print(power(A, K)[0] + 1)
