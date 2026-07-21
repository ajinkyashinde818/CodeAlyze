import sys
input = lambda: sys.stdin.readline().rstrip()

def main():
    s = input()
    s = s[::-1]
    flag = True

    i = 0
    while i < len(s):
        if s[i:i + 5] == 'maerd' or s[i:i + 5] == 'esare':
            i += 5
        elif s[i:i + 6] == 'resare':
            i += 6
        elif s[i:i + 7] == 'remaerd':
            i += 7
        else:
            flag = False
            break
    print('YES' if flag else 'NO')

if __name__ == '__main__':
    main()
