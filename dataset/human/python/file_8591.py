K, N = map(int, input().split())
A =list(map(int, input().split()))

KK = int(K)


def smaler(x, y):
  if x < y:
    return x
  else:
    return y

def lager(x, y):
  if x > y:
    return x
  else:
    return y

 

def span(A, i):
  if i == 1:
    return K - A[len(A) - 1] + A[0]
  elif i != 1:
    return A[i] - A[i - 1]
    
m = 0
for i in range(0, len(A)):
  m = lager(m, span(A, i))

  
print(K - m)
