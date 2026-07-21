import sys
sys.setrecursionlimit(10 ** 7)
read = sys.stdin.buffer.read 
input = sys.stdin.buffer.readline
def inputS(): return input().rstrip().decode()
readlines = sys.stdin.buffer.readlines 

N, R = map(int, input().split())

ans = 0
if N < 10:
  ans = (100*(10-N) + R)
else:
  ans = R
print(ans)
