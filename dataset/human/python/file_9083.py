def solve():
    s = ''.join(reversed(input()))
    words = [''.join(reversed(substr)) for substr in ["dream", "dreamer", "erase", "eraser"]]
    while True:
        word = [w for w in words if s.startswith(w)]
        if word:
            s = s[len(word[0]):]
            if not s:
                return "YES"
        else:
            return "NO"


if __name__ == "__main__":
    print(solve())
