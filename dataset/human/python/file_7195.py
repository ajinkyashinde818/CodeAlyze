def main():

    S = input()
    Q = int(input())

    reverse = False
    head = ''
    tail = ''

    for _ in range(Q):
        query= input()
        if query == '1':
            reverse = not reverse
            head, tail = tail, head
        else:
            _, f, c = query.split()
            if f == '1':
#                head = ''.join([head,c])
                head += c
            else:
#                tail = ''.join([tail,c])
                tail += c

    if reverse:
        S = S[::-1]

    print(''.join([head[::-1], S, tail]))

if __name__ == "__main__":
    main()
