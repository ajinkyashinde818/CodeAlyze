S=input()
def solve(query):
    while 1:
        if not query:
            print("YES")
            break

        for frag in ("erase","eraser","dream","dreamer"):
            if query.endswith(frag):
                query=query[:-len(frag)]
                break
        else:
            print("NO")
            break

solve(S)
