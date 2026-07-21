s = input()


def solve(query):
    while 1:
        for frag in ("erase", "eraser", "dream", "dreamer"):
            if query.endswith(frag):
                query = query[:-len(frag)]
                break
        else:
            print("NO")
            break
        if not query:
            print("YES")
            break



solve(s)
