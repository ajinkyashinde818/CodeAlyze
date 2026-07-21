s = input()

import re
output ="NO"
s = re.sub('dreameraser', 'A', s)
s = re.sub('dreamerase', 'A', s)
s = re.sub('dreamer', 'A', s)
s = re.sub('eraser', 'A', s)
s = re.sub('erase', 'A', s)
s = re.sub('dream', 'A', s)
if s.isupper() :
    output = "YES"
print(output)
