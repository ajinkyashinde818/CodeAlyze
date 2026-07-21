def ABC_78_A():
    X,Y = map(str, input().split())
    list1 = ['A','B','C','D','E','F']
    list2 = [10,11,12,13,14,15]
    
    if list2[list1.index(X)] > list2[list1.index(Y)]:
        print('>')
    elif list2[list1.index(X)] < list2[list1.index(Y)]:
        print('<')
    else:
        print('=')



if __name__ == '__main__':

    ABC_78_A()
