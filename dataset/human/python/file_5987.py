from sys import stdin

n = int(stdin.readline().rstrip())
a_lst = [int(x) for x in stdin.readline().rstrip().split()]
b_lst = [int(x) for x in stdin.readline().rstrip().split()]
c_lst = [int(x) for x in stdin.readline().rstrip().split()]
val = 0
prev = -100

for a in a_lst:
  val += b_lst[a-1]
  if prev + 1 == a:
    val += c_lst[a-2]
  prev = a
 
print(val)
