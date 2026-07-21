import sys
input = sys.stdin.readline


def main():
    s = input().strip()
    q = int(input())
    queries = [input().split() for _ in range(q)]
    pre = []
    post = []
    flg = True
    for query in queries:
        if query[0] == "1":
            flg = not flg
            continue
        if query[1] == "1":
            if flg:
                pre.append(query[2])
            else:
                post.append(query[2])
        else:
            if flg:
                post.append(query[2])
            else:
                pre.append(query[2])
    pre.reverse()
    pre.append(s)
    pre.extend(post)
    s = "".join(pre)
    if not flg:
        s = s[::-1]
    print(s)


if __name__ == "__main__":
    main()
