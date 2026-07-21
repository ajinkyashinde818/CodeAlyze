s = str(input())


def solve(query):
    while 1:
        for frag in ["dream", "dreamer", "erase", 'eraser']:
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
