import sys
n = int(input())
if n%2 == 1:
    print(0)
    sys.exit()
else:
    cur_two, cur_ten = 2, 10
    num_two, num_ten = 0, 0
    while cur_two <= n:
        num_two += n//cur_two
        cur_two *= 2
    while cur_ten <= n:
        num_ten += n//cur_ten
        cur_ten *= 5
    print(min(num_two, num_ten))
