INPUT_STR = input()


match_patterns = [
    ''.join(list(reversed('dream'))),
    ''.join(list(reversed('dreamer'))),
    ''.join(list(reversed('erase'))),
    ''.join(list(reversed('eraser')))
]

string = ''.join(list(reversed(INPUT_STR)))


def is_concatted_string(string):
    string = ''.join(list(reversed(string)))
    while len(string) != 0:
        for pattern in match_patterns:
            if string.startswith(pattern):
                string = string[len(pattern):]
                if len(string) == 0:
                    return True
                break
        else:
            return False
    return False


if INPUT_STR != '' and is_concatted_string(INPUT_STR):
    print('YES')
else:
    print('NO')
