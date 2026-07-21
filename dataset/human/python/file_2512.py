import sys

read = sys.stdin.buffer.read
readline = sys.stdin.buffer.readline
readlines = sys.stdin.buffer.readlines

d, g = map(int, readline().split())
pc = []
for _ in range(d):
    pc.append(readline().split())

def main(d, g, pc):
    min_cnt = 1000000000
    for i in range(2**d):
        wa = 0
        cnt = 0
        nokori = [i for i in range(d)]
        for j in range(d):
            if i & 2**j:
                wa += int(pc[j][1]) + 100 * int(pc[j][0]) * (j+1)
                cnt += int(pc[j][0])
                nokori.remove(j)
        if wa < g:
            if int(pc[nokori[-1]][0]) * 100 *(nokori[-1]+1) > int(g) - wa:
              if (g-wa) % (100 *(nokori[-1]+1)) != 0:
                  ato = 1 + (g-wa) // (100 *(nokori[-1]+1))
              else:
                  ato = (g-wa) // (100 *(nokori[-1]+1))
              cnt += ato
              wa += ato * 100 * (nokori[-1]+1)
        if g <= wa:
	        min_cnt = min(cnt, min_cnt)
    return min_cnt


print(main(d, g, pc))
