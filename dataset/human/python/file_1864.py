import numpy as np

def main():
  n,m = map(int,input().split())
  an = np.array([list(input()) for i in range(n)])
  bm = np.array([list(input()) for i in range(m)])
  
  for i in range(n-m+1):
    for j in range(n-m+1):
      if (an[i:i+m,j:j+m] == bm).all():
        print('Yes')
        exit()
  print('No')
if __name__ == '__main__':
    main()
