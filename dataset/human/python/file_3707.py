from sys import stdin

def waru(a,b):
  if a%b != 0:
    return 0
  if a/b == 1:
    return b
  return waru(a/b,b)
  

def main():
  s = []
  read = stdin.readline
  N =int(read())
  if N == 1:
    print(0)
    exit()
  i = 2
  table = []
  ap = table.append
  while i * i <= N:
    while N%i == 0:
      ap(i)
      N //= i
    i += 1
  if N > 1:
    ap(N)
  set_table = sorted(list(set(table)))
  kaisu = [0] * len(set_table)
  num = 0
  for i in table:
    if i == set_table[num]:
      kaisu[num] += 1
    else:
      num += 1
      kaisu[num] += 1
  maxk = max(kaisu)
  j = 1
  k = 0
  count = 0
  while j <= maxk:
    count += len([i for i in kaisu if i >= j])
    k += 1
    j = j + k + 1
  print(count)
    
      
      

  
  
  
if __name__ == "__main__":
  main()
