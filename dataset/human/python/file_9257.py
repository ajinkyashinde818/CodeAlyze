def erase_end(string):
    if string.endswith("dream"):
        string = string[:-5]
    elif string.endswith("dreamer"):
        string = string[:-7]
    elif string.endswith("erase"):
        string = string[:-5]
    elif string.endswith("eraser"):
        string = string[:-6]
    elif string == "":
        string = "YES"
    else:
        string = "NO"
    return string
    
string = input()

while True:
    if string == "YES" or string == "NO":
        break
    string = erase_end(string)

print(string)
