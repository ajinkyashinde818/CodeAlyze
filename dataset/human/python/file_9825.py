def main():
  N, K = map(int, input().split())
  A_list = input().split()

  root = [1]

  record = [-1]*N
  break_flag = 0
  for n in range(K):
    new = int(A_list[ int(root[n])-1 ])
    if record[new-1] <0:
      record[new-1]=1
      root.append(new)
    else:
      ind = root.index(new)
      break
  else:
    print(new)
    break_flag = 1
    
  if break_flag == 0:  
	  pre = len(root[:ind])
	  roop = len(root)-pre

	  print(root[ind:][(K-pre)%roop])
   
if __name__ == '__main__':
  main()
