def main():
    from functools import lru_cache
    import sys
    sys.setrecursionlimit(10 ** 7)

    WORDS = 'dream', 'dreamer', 'erase', 'eraser'

    S = input()
    N = len(S)

    @lru_cache(maxsize=None)
    def dfs(cur=N):
        if cur == 0:
            return True

        for word in WORDS:
            if S[cur - len(word):cur] == word:
                if dfs(cur - len(word)):
                    return True

        return False

    cond = dfs()
    print('YES' if cond else 'NO')


if __name__ == '__main__':
    main()
