from itertools import combinations

import numpy as np


def run():
    n, k = map(int, input().split())
    a_list = list(map(int, input().split()))

    history = [0 for _ in a_list]

    history[0] = 1

    current_a = 1
    loop_num = 0
    history_flag = True
    while True:
        next_a = a_list[current_a - 1]

        if history[next_a - 1] != 0 and history_flag:
            pre_visit = history[next_a - 1]
            current_visit = loop_num + 2

            same_loop_num = (current_visit - pre_visit)

            loop_num += same_loop_num * ((k - loop_num) // same_loop_num - 1)
            history_flag = False
            # print('hit')
            # print(loop_num)
            # print(same_loop_num)

        history[next_a - 1] = loop_num + 2
        current_a = next_a

        loop_num += 1
        if loop_num == k:
            print(current_a)
            exit()
        if loop_num > k:
            print('error')
            print(loop_num)
            print(k)
            raise ValueError()


if __name__ == '__main__':
    run()
