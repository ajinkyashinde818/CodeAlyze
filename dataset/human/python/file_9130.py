import sys
s = input()
while len(s)>7:
    if s[:6]=="dreamd":
        s = s.replace("dream","",1)
        continue
    if s[:6]=="erased":
        s = s.replace("erase","",1)
        continue
    if s[:6]=="eraser":
        s = s.replace("eraser","",1)
        continue
    if s[:6]=="erasee":
        s = s.replace("erase","",1)
        continue
    if s[:8]=="dreamerd":
        s = s.replace("dreamer","",1)
        continue
    if s[:8]=="dreamera":
        s = s.replace("dream","",1)
        continue
    if s[:8]=="dreamere":
        s = s.replace("dreamer","",1)
        continue
    break
if s in ["dream","dreamer","erase","eraser"]:
    print("YES")
else:
    print("NO")
