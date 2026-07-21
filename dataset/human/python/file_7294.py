from sys import stdin

def main():

    input = stdin.readline

    S = input()[:-1]
    Q = int(input())
    
    query = [0] * Q
    ans_list = []

    reverse_flag = False

    mae = []
    ushiro = []

    for i in range(Q):
        query = input().split()
        if(query[0] == '1'):
            reverse_flag = not reverse_flag
        else:
            if reverse_flag is True:
                if(query[1] == '1'):
                    ushiro.append(query[2])
                else:
                    mae.append(query[2])                
            else:
                if(query[1] == '1'):
                    mae.append(query[2])
                else:
                    ushiro.append(query[2])
    
    ans_list = "".join(mae[::-1]) + S + "".join(ushiro)
    
    if(reverse_flag is not True):
        print(''.join(ans_list))
    else:
        print(''.join(ans_list[::-1]))


if __name__ == "__main__":
    main()
