SIZE = 3001
def main():
    output = 0
    R, G, B, N = (int(_) for _ in input().split())
    for r in range(SIZE):
      for g in range(SIZE):
        b = N - r * R - g * G
        if 0 <= b and b%B == 0: output += 1
    print(output)
    return

if __name__ == '__main__':
    main()
