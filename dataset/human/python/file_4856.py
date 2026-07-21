def main():
    s = input()
    s_list = list(s)
    s_list.sort()

    t = input()
    t_list = list(t)
    t_list.sort(reverse = True)

    for i in range(0,min(len(s_list),len(t_list))):
        if s_list[i] < t_list[i]:
            print("Yes")
            return
        elif s_list[i] > t_list[i]:
            print("No")
            return

    if len(s_list) < len(t_list):
        print("Yes")
    else:
        print("No")

    return

if __name__ == "__main__":
    main()
