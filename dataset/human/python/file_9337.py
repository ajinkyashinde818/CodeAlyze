import sys
def Ii():return int(sys.stdin.buffer.read())
def Mi():return map(int,sys.stdin.buffer.readline().split())
def Li():return list(map(int,sys.stdin.buffer.readline().split()))

n,k = Mi()
a = Li()
b = [1]
b.append(a[0])
flag = False
for i in range(n):b.append(a[b[-1]-1])
if len(b) > k:
  print(b[k])
  exit(0)
for j in range(len(b)):
  if b[j] == a[b[-1]-1]:
    break
    
roop = len(b)-j
roopk = (k-j)%roop
print(b[roopk+j])
