N = int(input())
A = list(map(int,input().split()))
B = list(map(int,input().split()))
C = list(map(int,input().split()))

def buffet(N,x,y,z):
  a = sum(y)
  for i in range(N-1):
    if x[i+1] - x[i] == 1:
      a = a + z[x[i]-1]
  print(a)

if __name__ == '__main__':
  buffet(N,A,B,C)
