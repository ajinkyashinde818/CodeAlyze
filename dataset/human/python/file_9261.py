import re

def main():
    S = input()
    pattern = r'^(dream|dreamer|erase|eraser)+$'
    rep = re.compile(pattern)
    result = rep.match(S)
    if result:
        print("YES")
    else:
        print("NO")
    pass

if __name__ == "__main__":
    main()
    pass
