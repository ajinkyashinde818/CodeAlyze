import math
from collections import deque
def main():
    s = deque(input())
    q = int(input())

    counter = 0
    for _ in range(q):
        query = [t for t in input().split()]
        if len(query)==1:
            counter +=1

        else:
            f = (counter+int(query[1]))%2
            if f==1:
                s.appendleft(query[2])
            else:
                s.append(query[2])

    s = list(s)
    if counter%2==1:
        s = s[::-1]

    for c in s:
        print(c,end='')

    print()


if __name__ == "__main__":
    main()
