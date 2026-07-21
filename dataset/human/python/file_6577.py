import sys
def main():
    input = sys.stdin.readline
    S = input().rstrip()
    Q = int(input())
    prefix = []
    suffix = []
    reverse = False
    for _ in range(Q):
        q = input().rstrip().split()
        if q[0] == '1': reverse = not reverse
        else:
            is_pre = (q[1] == '1' and reverse == False) or (q[1] == '2' and reverse)
            if is_pre:
                prefix.append(q[2])
            else:
                suffix.append(q[2])

    if reverse:
        S = S[::-1]
        prefix, suffix = suffix, prefix
    prefix.reverse()
    print(''.join(prefix) + S + ''.join(suffix))

if __name__ == '__main__':
    main()
