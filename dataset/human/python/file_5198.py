def main():
  N, M, *AB = map(int, open(0).read().split())

  inter, goalable = set(), set()
  
  iterator = iter(AB)
  for a, b in zip(iterator, iterator):
    if a == 1:
      inter.add(b)
    
    if b == N: 
      goalable.add(a)
      
  flag = inter & goalable
  print("POSSIBLE" if flag else "IMPOSSIBLE")
  
if __name__ == "__main__":
    main()
