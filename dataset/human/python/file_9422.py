def main():
  n, k = map(int, input().split())

  A = tuple(map(lambda a: int(a) - 1, input().split()))

  arrival = [None] * n
  arrival[0] = 0

  pos = 0
  for i in range(1, k + 1):
    next_pos = A[pos]

    if arrival[next_pos]:
      loop_len = i - arrival[next_pos]
      remaining = k - i
      kk = arrival[next_pos] + remaining % loop_len
      print(arrival.index(kk) + 1)
      return

    arrival[next_pos] = i
    pos = next_pos

  print(pos + 1)


main()
