def main():
    N = int(input())
    take_dish = list(map(int,input().split()))
    dish_point = list(map(int,input().split()))
    bonus_dish_point = list(map(int,input().split()))
    result = 0

    for index,dish in enumerate(take_dish):
        result += dish_point[dish-1]
        if(index!=0 and (take_dish[index-1]+1 == dish)):
            result += bonus_dish_point[take_dish[index-1]-1]
    
    print(result)
        

if __name__ == "__main__":
    main()
