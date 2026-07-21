import sys
li = ["dream","dreamer","erase","eraser"]
li = [s[::-1] for s in li]
sen = input()[::-1]
while 1:
  ju = 0
  for i in range(4):
    le = len(li[i])
    if sen[:le] == li[i]:
      if len(sen) == le:
        print("YES")
        sys.exit()
      else:
        sen = sen[le:]
        ju = 1
  if not ju:
    print("NO")
    sys.exit()
