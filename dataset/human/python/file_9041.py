def main():
    s = input()
    num = 0

    while num < len(s) - 7:
        if s[num:num+6] == "dreamd" or s[num:num+8] == "dreamera":   #"dream"確定
            num += 5
        elif s[num:num+8] == "dreamerd" or s[num:num+8] == "dreamere":  #"dreamer"確定
            num += 7
        elif s[num:num+6] == "erased" or s[num:num+6] == "erasee":    #"erase"確定
            num += 5
            #print('erase')
        elif s[num:num+7] == "eraserd" or s[num:num+7] == "erasere":    #"eraser"確定
            num += 6
        else:
            print("NO")
            exit()
    if s[num:num+5] == "dream" or s[num:num+7] == "dreamer" or s[num:num+5] == "erase" or s[num:num+6] == "eraser":
        print('YES')
    else:
        print('NO')


if __name__ == "__main__":
    main()
