str = input()
def check_str(str, ans):
    return str.find(ans)

if(check_str(str, "a") == -1):
    print("No")
elif(check_str(str, "b") == -1):
    print("No")
elif(check_str(str, "c") == -1):
    print("No")
else:
    print("Yes")
