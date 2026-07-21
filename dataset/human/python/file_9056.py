def main():
  a = input()
  
  flg = "YES"
  index = 0
  while True:
    if index == len(a):
      break
    
    if a.find("dreameraser", index) == index:
      index += len("dreameraser")
    elif a.find("dreamerase", index) == index:
      index += len("dreamerase")
    elif a.find("dreamer", index) == index:
      index += len("dreamer")
    elif a.find("dream", index) == index:
      index += len("dream")
    elif a.find("eraser", index) == index:
      index += len("eraser")
    elif a.find("erase", index) == index:
      index += len("erase")
    else:
      flg = "NO"
      break
      
  print(flg)
  
main()
