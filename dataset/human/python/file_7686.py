import sys

while True:
    N = int(sys.stdin.readline().rstrip())
    if N == 0:
        break;
    max_value = 0
    prev_row = [0] * (N+1)
    for i in range(N):
        row = sys.stdin.readline().rstrip()
        curr_row = [0] * (N+1)
        for x,d in enumerate(row,1):
            if d == '.':
                curr_row[x] = min(prev_row[x-1], prev_row[x], curr_row[x-1]) + 1
        max_value = max(max(curr_row), max_value)
        prev_row = curr_row

    print(max_value)
