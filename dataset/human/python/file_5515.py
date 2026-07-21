def main():
    s = input().split()
    for i in range(2):
        if(s[i]=="A"):
            s[i]=10
        elif(s[i]=="B"):
            s[i]=11
        elif(s[i]=="C"):
            s[i]=12
        elif(s[i]=="D"):
            s[i]=13
        elif(s[i]=="E"):
            s[i]=14
        elif(s[i]=="F"):
            s[i]=15
    if(s[0]>s[1]):
        print(">")
    elif(s[0]<s[1]):
        print("<")
    else:
        print("=")
    
main()
