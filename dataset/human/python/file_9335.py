n,k = map(int,input().split())
a_list = list(map(int,input().split()))
past_a = [1]
first = 0
for i in range(n):
    past_a.append(a_list[past_a[-1] - 1])
    
def check(past_a):
  if len(past_a) == len(set(past_a)):
    return True
  else:
    return False
  
left = 0
right = len(past_a)

while right - left > 1:
  middle = (right + left)//2
  if check(past_a[:middle]) == True:
    left = middle
  else:
    right = middle
roop_2 = left 
roop_1 = past_a.index(past_a[roop_2])
unit = roop_2 - roop_1
p_unit = past_a[roop_1:roop_2]
if k <= left:
  print(past_a[k])
else:
  k = (k - left) % unit
  print(p_unit[k])
