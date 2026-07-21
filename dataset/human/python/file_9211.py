def solve(n):

    while len(n) > 4:
        if n[-5:] == "dream":
            n = n[:-5]
        elif n[-7:] == "dreamer":
            n = n[:-7]
        elif n[-5:] == "erase":
            n = n[:-5]
        elif n[-6:] == "eraser":
            n = n[:-6]
        else:
            break

    return "YES" if len(n) == 0 else "NO"

if __name__ == "__main__":
    n = input()
    print(solve(n))
