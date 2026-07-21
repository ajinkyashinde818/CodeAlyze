from sys import stdin
input = stdin.readline
def minus(n):
  return n-1
  
def main():
  num_list = list(map(int, input().split()))
  A = list(map(int, input().split()))
  N=num_list[0]
  K=num_list[1]
  A_i=0
  N_list=[0]*N
  A =list(map(minus, A))
  sFlag=True
  i=0
  while(sFlag):
    i=i+1
    pre=A_i
    N_list[A_i]+=1
    if(N_list[A_i]==3):
      sumA=N_list.count(int(2))
      sumA=sumA+N_list.count(int(3))
      K=(K-i)%sumA+1
      for j in range(K):
        pre=A_i
        te=A[A_i]
        A_i=te
      sFlag=False
      break
    te=A[A_i]
    A_i=te
    if(i>=K):
      sFlag=False
      break
  print(A_i+1)
  
if __name__ == '__main__':
    main()
