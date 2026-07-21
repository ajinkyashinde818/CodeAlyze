import re

s = input()

candidates = ["dream", "dreamer", "erase", "eraser"]
ok = False
t = ""

pattern = r"^(dream|dreamer|erase|eraser)*$"
repatter = re.compile(pattern)
match_obj = repatter.match(s)

if match_obj:
    print("YES")
else:
    print("NO")
