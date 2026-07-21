import math

s = input()
q = int(input())
reverse_flag = 0
head = ""
tail = ""

for i in range(q):
  query = input().split(" ")
  if(len(query) == 1):
    reverse_flag += 1
  else:
    if((reverse_flag + int(query[1])) % 2 == 0):
      tail += query[2]
    else:
      head = query[2] + head

ans_str = head + s + tail

if(reverse_flag % 2 == 1): print(ans_str[::-1])
else: print(ans_str)
