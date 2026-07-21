N, K = map(int,input().split())
A = list(map(int,input().split()))

count = 0
i = 1
position = 1
position_list = [1]
position_history = [0] * N
start_loop = 0
def last():
  k = (K - start_loop) % (count - start_loop)
  print(position_list[start_loop+k])

while i > 0:
  position = A[position-1]
  position_history[position-1] += 1
  count += 1
  if count == K:
    print(position)
    break
  elif position_history[position-1] > 1:
    start_loop = position_list.index(position)
    position_list.append(position)
    last()
    break
  else:
    position_list.append(position)
