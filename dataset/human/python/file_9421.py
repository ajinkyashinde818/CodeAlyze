n, k = map(int, input().split())
a = list(map(int, input().split()))
def get_cycle_length():
  pointer1 = 1
  pointer2 = a[1-1]
  while pointer1 != pointer2:
    pointer2 = a[pointer2-1]
    pointer2 = a[pointer2-1]
    pointer1 = a[pointer1-1]
  cycle_length = 1
  pointer2 = a[pointer2-1]
  while pointer1 != pointer2:
    pointer2 = a[pointer2-1]
    cycle_length += 1
  return cycle_length
def get_start_length(cycle_length):
  pointer1 = 1
  pointer2 = 1
  for _ in range(cycle_length):
    pointer2 = a[pointer2-1]
  start_length = 0
  while pointer1 != pointer2:
    start_length += 1
    pointer1 = a[pointer1-1]
    pointer2 = a[pointer2-1]
  return start_length
if k>n:
  cycle_length = get_cycle_length()
  start_length = get_start_length(cycle_length)
  remainder_steps = k - start_length
  modded_remainder = remainder_steps % cycle_length
  k = start_length + modded_remainder
town = 1
for _ in range(k):
  town = a[town-1]
print(town)
