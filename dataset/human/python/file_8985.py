from itertools import permutations

S = input()

def is_passed(s, ws):
    for w in ws:
        s = ''.join(s.split(w))
        if len(s) == 0:
            return True
    return False

def main():
    l = ['dreamer', 'eraser', 'dream', 'erase']
    pm = permutations(l, len(l))
    passed = False
    for ws in pm:
        passed = is_passed(S, ws)
        if passed:
            break
    print('YNEOS'[not passed::2])

if __name__ == '__main__':
    main()
