def begginer(k, x):
    print(x + 100 * (10 - min(10, k)))

if __name__ == "__main__":
    import sys
    in_str = []
    for line in sys.stdin:
        in_str.append(line)
    k, x = [int(_) for _ in in_str[0].split(' ')]
    begginer(k, x)
