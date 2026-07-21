from sys import stdin
input = stdin.readline


def main():
  N, K = list(map(int, input().split()))
  A = list(map(int, input().split()))

  non_loop_time = 0
  loop_time = 0
  time = [0]*(N+1)
  stack = [1]
  visited = set()
  visited.add(1)
  t = 0
  root = [1]

  while len(stack):

    t += 1
    now = stack[-1]
    time[now] = t
    next_ = A[now-1]

    if next_ not in visited:
      root.append(next_)
      visited.add(next_)
      stack.append(next_)
    else:
      non_loop_time = time[next_] - 1
      loop_time = time[now] - time[next_] + 1
      break

  if K <= non_loop_time:
    print(root[K])
  else:
    K -= non_loop_time
    K %= loop_time
    print(root[non_loop_time+K])


if(__name__ == '__main__'):
  main()
