import re
moji = str(input())
moji = re.sub("eraser", "", moji)
moji = re.sub("erase", "", moji)
moji = re.sub("dreamer", "", moji)
moji = re.sub("dream", "", moji)
 
if len(moji) == 0:
    print("YES")
else:
    print("NO")
