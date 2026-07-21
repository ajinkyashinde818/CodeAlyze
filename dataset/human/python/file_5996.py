if __name__ == "__main__":
 
    n = int(input())
    a_list = input().split()
    b_list = input().split()
    c_list = input().split()
    
    points = 0
    for i, a in enumerate(a_list):
        points += int(b_list[int(a) - 1])
        if i >= 1 and int(a_list[i]) == int(a_list[i - 1]) + 1:
            points += int(c_list[int(a_list[i - 1]) - 1])
    
    print('{0}'.format(points))
