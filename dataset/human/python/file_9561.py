import sys
from typing import Callable, List, NoReturn, Tuple


def main() -> NoReturn:
    scan: Callable[[], str] = sys.stdin.readline

    n, k = map(int, scan().rstrip().split())
    a: Tuple[int] = tuple(int(a_i) - 1 for a_i in scan().rstrip().split())

    flag: List[bool] = [False] * n
    path: List[int] = []

    current_city: int = 0
    prev_city: int = -1

    while not flag[current_city]:
        flag[current_city] = True
        path.append(current_city)
        prev_city = current_city
        current_city = a[current_city]

    start_loop_index: int = path.index(current_city)

    if k < len(path):
        print(path[k] + 1)
    else:
        index_in_loop: int = (k - start_loop_index) % (len(path) - start_loop_index)
        print((path[start_loop_index:])[index_in_loop] + 1)


if __name__ == '__main__':
    main()
