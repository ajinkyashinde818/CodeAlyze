import itertools
from typing import List, Tuple


def main():
    d, g = map(int, input().split())
    v = []
    for _ in range(d):
        p, c = map(int, input().split())
        v.append((p, c))

    print(ag(v, g))


def ag(v: List[Tuple[int, int]], g: int) -> int:
    # ex. [(3, 500), (5, 800)] -> [(1, 3, 500), (2, 5, 800)]
    v = [(i + 1, v[i][0], v[i][1]) for i in range(len(v))]

    result = 100 ** 10

    for j in range(len(v) + 1):
        for cb in itertools.combinations(v, j):
            sc = 0
            cnt = 0
            # calc bonus score
            for (i, p, c) in cb:
                sc += i * 100 * p + c
                cnt += p

            for idx in reversed(range(len(v))):
                if sc >= g:
                    break
                if v[idx] in cb:
                    continue
                i, p, _ = v[idx]
                for _ in range(p - 1):
                    if sc >= g:
                        break
                    sc += i * 100
                    cnt += 1

            if sc >= g:
                result = min(result, cnt)
    return result


if __name__ == '__main__':
    main()
