def main():
    S = input()
    if S.replace("eraser", "").replace("erase", "").replace("dreamer", "").replace("dream", ""):
        return print("NO")
    else:
        return print("YES")


if __name__ == '__main__':
    main()
