t=input()

def right(text):
  li=["dream","dreamer","erase","eraser"]
  for te in li:
    if text[-len(te):] == te:
      return text[:len(text)-len(te)]
  return text

flag=True
while flag:
  temp=right(t)
  if not temp:
    print("YES")
    break
  elif temp==t:
    print("NO")
    break
  t=temp
