import queue
def reverse(s):
  ret = ''
  len_ = len(s) - 1
  for i in range(len(s)):
    ret += s[len_ - i]
  return ret

S = input()
N = int(input())


p_a = queue.LifoQueue()
rp_a = queue.Queue()
p_b = queue.Queue()
rp_b = queue.LifoQueue()
flag = False
for i in range(N):
  s = input()
  if s[0] == '1':
    flag = not flag   
  else:
    if (s[2] == '2' and not flag) or (s[2] == '1' and flag) :
      p_b.put(s[4])
    elif (s[2] == '2' and flag) or (s[2] == '1' and not flag) :
  	  p_a.put(s[4])
s_a = ''
s_b = ''
while not p_a.empty():
  s_a += p_a.get()
while not p_b.empty():
  s_b += p_b.get()
ret = s_a + S + s_b
if flag:
  ret = reverse(ret)

print(ret)
