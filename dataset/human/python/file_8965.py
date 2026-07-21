import sys

s = input()
data = {"dream","dreamer","erase","eraser"}

while True:
    for i in data:
        if s.endswith(i):
            s = s[:-len(i)]
            break
    else:break

if s == "":
    print("YES")
    sys.exit()
else:
    print("NO")
    sys.exit()
