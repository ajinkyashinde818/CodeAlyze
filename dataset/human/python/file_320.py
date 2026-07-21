import math

def main():
  n = int(input())
  a = list(map(int, input().split()))

  count = 0
  sum = 0
  min_number = 10000000000
  for i in a:
    count += 1 if i<0 else 0
    sum += abs(i)
    min_number = min(min_number, abs(i))
    
  if count % 2 == 0:
    print(sum)
  else:
    print(sum - min_number*2)
  
main()
