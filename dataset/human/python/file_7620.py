import sys
input = sys.stdin.readline


def main():
    S = input().rstrip()
    Q = int(input())
    reverse_flag = False
    head = ''
    tail = ''
    for _ in range(Q):
        q = input().rstrip()
        if q == '1':
            reverse_flag = not reverse_flag
        else:
            _, F, C = q.split()
            if (F == '1' and reverse_flag is False) or (F == '2' and reverse_flag is True):
                head += C
            else:
                tail += C
    if reverse_flag is True:
        print(tail[::-1] + S[::-1] + head)
    else:
        print(head[::-1] + S + tail)


if __name__ == '__main__':
    main()
