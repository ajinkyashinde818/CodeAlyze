def resolve():
  N, K = map(int, input().split(" "))
  A = [int(x) - 1 for x in input().split(" ")]

  current = 0
  if K < N:
    for i in range(K):
      current = A[current]
    print(current + 1)
    return True
  else:
    history = [False] * N
    load_map = []
    while True:
      load_map.append(current)
      current = A[current]
      if history[current]:
        loop_length = len( load_map[load_map.index(current):] )
        if loop_length == 0:
          print(current + 1)
          return True

        length_to_loop = len( load_map[:load_map.index(current)] )
        additional_way = (K-length_to_loop)%loop_length
        print(load_map[length_to_loop + additional_way] + 1)
        return True
      else:
        history[current] = True

if __name__ == "__main__":
    resolve()
