from collections import namedtuple
from math import ceil

Problem = namedtuple('Problem', ('count', 'bonus'))

def main():
    d, g = map(int, input().split())
    problems = []
    for _ in range(d):
        count, bonus = map(int, input().split())
        problems.append(Problem(count, bonus))
    
    print(solve(d, g, problems))

def solve(d, g, problems):
    r = float('inf')

    for i in range(2 ** d):
        k = -1
        score = 0
        count = 0
        for j in range(d):
            if (i >> j) & 0x01 != 0:
                score += 100 * (j + 1) * problems[j].count + problems[j].bonus
                count += problems[j].count
            else:
                k = j
        
        if score >= g:
            r = min(r, count)
        else:
            c = ceil((g - score) / (100 * (k + 1)))
            if c <= problems[k].count:
                r = min(r, count + c)

    return r

main()
