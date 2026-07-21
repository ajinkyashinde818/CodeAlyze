def read_int():
    return int(input().strip())


def read_ints():
    return list(map(int, input().strip().split(' ')))


def solve():
    '''
    dreamer
      dream
     eraser
      erase
    '''
    strings = ['dreamer', 'dream', 'eraser', 'erase']
    for i in range(len(strings)):
        strings[i] = ''.join(reversed(strings[i]))
    S = input().strip()
    S = ''.join(reversed(S))
    i = 0
    while i < len(S):
        found_string = None
        for string in strings:
            if S[i:].startswith(string):
                found_string = string
                break
        if found_string is None:
            return 'NO'
        i += len(found_string)
    return 'YES'


if __name__ == '__main__':
    print(solve())
