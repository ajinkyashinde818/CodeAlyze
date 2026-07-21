N, M = map(int, input().split())
A = [list(input()) for _ in range(N)]
B = [list(input()) for _ in range(M)]

def is_same(si, sj, A, B):
     for i in range(M):
          for j in range(M):
               if A[si+i][sj+j] != B[i][j]:
                    return False
     return True

def main():
     for i in range(N-M+1):
          for j in range(N-M+1):
               if is_same(i,j, A, B):
                    return True
     return False

if main():
     print("Yes")
else:
     print("No")
