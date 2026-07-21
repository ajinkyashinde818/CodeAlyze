import sys
input = sys.stdin.readline
sys.setrecursionlimit(10**6)


def main():
    s = str(input())
    q = int(input())
    s = s.strip()
    a = [''] * (10**5*2)
    a.extend(list(s))
    a.extend([''] * (10**5*2))
    start = 10**5*2
    end = start + len(s) - 1
    frip = False
    for i in range(q):
        query = input().split()
        if query[0] == '1':
            frip = not frip
        elif query[0] == '2':
            if (query[1] == '1' and frip == False) or (query[1] == '2' and frip == True):
                a[start-1] = query[2]
                start -= 1
            else:
                a[end+1] = query[2]
                end += 1
    if frip:
        a.reverse()
        tmp = end
        end = len(a)-start-1
        start = len(a)-tmp-1
    print(''.join(a[start:end+1]))


main()
