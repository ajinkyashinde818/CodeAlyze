A, B = map(int,input().split())
def min2(A,B):
  C = abs(A - B)
  D = [A, B, C]
  D.sort()
  if D[0] == 1:
    return 1
  elif D[0] == D[1]:
    return D[0]
  else:
    return min2(D[0],D[1])
a = min2(A,B)

print(int(A*B/a))
