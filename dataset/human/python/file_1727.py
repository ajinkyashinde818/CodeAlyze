if __name__ == '__main__':
  n, m = map(int, input().split())
  a_lst = []
  for i in range(n):
    a_lst.append(input())
  b_lst = []
  for i in range(m):
    b_lst.append(input())
  for j in range(n-m+1):
    for k in range(n-m+1):
      flag = 0
      for l in range(m):
        if a_lst[k+l][j:j+m] != b_lst[l]:
          flag = 1
          break
      if flag == 0:
        break
    if flag == 0:
      break
  if flag == 0:
    print("Yes")
  else:
    print("No")
