from itertools import accumulate
def main():
  N = int(input())
  A = [int(_) for _ in input().split()]
  B = list(accumulate(A))
  s = B[-1]
  B = [abs(2 * b - s) for b in B]
  print(min(B[:-1]))
  return

if __name__ == '__main__':
  main()
