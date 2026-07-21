data = [str(input()), True]

def check(string):
    if string[len(string)-6:] == 'eraser':
        string = string[:len(string)-6]
        return [string,True]
    elif string[len(string)-5:] == 'erase':
        string = string[:len(string)-5]
        return [string,True]
    elif string[len(string)-7:] == 'dreamer':
        string = string[:len(string)-7]
        return [string,True]
    elif string[len(string)-5:] == 'dream':
        string = string[:len(string)-5]
        return [string,True]
    else:
        return [string,False]
        
while (data[1] == True):
    data = check(data[0])
    if data[0] == '':
        print('YES')
        break
    elif data[1] == False:
        print('NO')
        break
