import sys
read = sys.stdin.buffer.read
readline = sys.stdin.buffer.readline
readlines = sys.stdin.buffer.readlines

n = int(readline())
if n <= 9 or n % 2 == 1:
  print(0)
  quit()
r = n // 10

for j in range(1, 25):
  r += n // ((5 ** j) * 10)

print(r)
