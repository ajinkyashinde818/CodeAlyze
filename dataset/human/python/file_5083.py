from collections import defaultdict

import sys
input = sys.stdin.readline

def main():
    num_land, num_ship = map(int, input().split())
    data = [list(map(int, input().split())) for i in range(num_ship)]

    move_dic = defaultdict(set)

    for i in range(num_ship):
        a, b = data[i]
        move_dic[a].add(b)
        move_dic[b].add(a)

    next_land = move_dic[1]
    for ele in next_land:
        aaa = move_dic[ele]
        if num_land in aaa:
            print('POSSIBLE')
            break
    else:
        print('IMPOSSIBLE')

if __name__ == '__main__':
    main()
