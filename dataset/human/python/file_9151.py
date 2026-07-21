str = input()
words = ["dream", "dreamer", "erase", "eraser"]

def replace(S, s):
    reversedS = S[::-1]
    reverseds = s[::-1]
    replaced = reversedS.replace(reverseds, "", 1)
    return replaced[::-1]

while True:
    tmp = str
    for word in words:
        if str.endswith(word):
            str = replace(str, word)
            break
    if tmp == str:
        print("NO")
        break
    if str == "":
        print("YES")
        break
    tmp = str
