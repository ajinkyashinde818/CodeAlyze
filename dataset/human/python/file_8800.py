import sys


input = sys.stdin.readline


def main():
  k, n = map(int, input().rstrip().split())
  a = [int(_) for _ in input().rstrip().split()]
  
  dist = [(a[i] - a[i - 1]) % k for i in range(n)]
  
  print(k - max(dist))


if __name__ == "__main__":
  main()
