import sys
import re

if sys.platform =='ios':
    sys.stdin=open('input_file.txt')


S=input()
s=S.replace("eraser","").replace("erase","").replace("dreamer","").replace("dream","")

if s:
	print("NO")
else:
	print("YES")
