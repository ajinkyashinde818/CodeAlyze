def main():
  k, N = (int(x) for x in input().split())
  min_LIST = []
  LIST = []
  LIST = list(map(int,input().split()))
  x = 0

  for i in range(len(LIST) - 1):
    min_LIST.append(LIST[i + 1] - LIST[i])
    if(x <= min_LIST[i]):
      x = min_LIST[i]

  if(N != 2):
    min_LIST.append(LIST[0] + (k - LIST[-1]))
    if(x <= (LIST[0] + (k - LIST[-1]))):
      x = (LIST[0] + (k - LIST[-1]))

  sum_list = sum(min_LIST) - x

  print(sum_list)
if __name__ == "__main__":
  main()
