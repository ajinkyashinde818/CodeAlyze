import sequtils, strutils, sets, unicode

var input = stdin.readLine()
let setc = toSet(['a', 'd', 'e', 'm', 'r', 's'])
echo(
    if input == "":
            "NO"
    elif toSet(input) <= setc :
        if input.replace("eraser", " ").replace("erase", " ").replace("dreamer", " ").replace("dream", " ").replace(" ", "") == "": 
            "YES" 
        else:
            "NO"
    else: 
        "NO"
)
