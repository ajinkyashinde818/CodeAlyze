from sys import stdin
nii=lambda:map(int,stdin.readline().split())

def main():
  n,m=nii()

  tree=[[] for i in range(n)]
  for i in range(m):
    a,b=nii()
    a-=1
    b-=1
    tree[a].append(b)
    tree[b].append(a)

  for i in tree[0]:
    for j in tree[i]:
      if j==n-1:
        print('POSSIBLE')
        exit()
  print('IMPOSSIBLE')

if __name__=="__main__":
  main()
