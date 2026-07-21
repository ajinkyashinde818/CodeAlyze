def main():
  k, n = map(int, input().split())
  max_range = 0
  first = True
  first_range = 0
  pre_range = 0
  for i in [int(i) for i in input().split()]:
    if first:
      first = False
      first_range = i
      pre_range = i
      continue
    
    if max_range < i - pre_range:
      max_range = i - pre_range
    
    pre_range = i
  
  if max_range < first_range + (k - pre_range):
    max_range = first_range + (k - pre_range)
  
  return k - max_range

print(main())
