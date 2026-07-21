def solve():
    s = input()

    invs = ''.join(list(reversed(s)))

    while 1:
        for f in map(lambda x: ''.join(list(reversed(x))), ["erase", "eraser", "dream", "dreamer"]):
            if invs.startswith(f):
                invs = invs[len(f):]
                break
            if invs == "":
                print("YES")
                return
        else:
            print("NO")
            return


if __name__ == '__main__':
    solve()
