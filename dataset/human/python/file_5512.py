def main():
    while True:
        try:
            inputList = input().split()
            firstChar = inputList[0]
            secondChar = inputList[1]
            firstNum = ord(firstChar)
            secondNum = ord(secondChar)
            if(firstNum > secondNum):
                print(">")
            elif(firstNum < secondNum):
                print("<")
            elif(firstNum == secondNum):
                print("=")
        except:
            break
main()
