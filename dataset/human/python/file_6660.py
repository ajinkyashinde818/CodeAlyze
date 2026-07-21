def solve(string):
    s, q, *qs = string.split("\n")
    pre = []
    post = []
    r = False
    for _q in qs[::-1]:
        if _q == "1":
            r = not r
            continue
        _, f, c = _q.split()
        if r and f == "2" or not r and f == "1":
            pre.append(c)
        else:
            post.append(c)
    pre, post = "".join(pre), "".join(post[::-1])
    return pre + s[::-1] + post if r else pre + s + post


if __name__ == '__main__':
    import sys
    print(solve(sys.stdin.read().strip()))
