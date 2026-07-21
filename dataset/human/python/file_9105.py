def main():
    s = input()
    s = s.replace("eraser","").replace("erase","").replace("dreamer","").replace("dream","")

    if s == "":
        print("YES")
    else:
        print("NO")

if __name__ == "__main__":
        main()
