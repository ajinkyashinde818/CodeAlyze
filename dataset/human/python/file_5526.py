def main():
    a, b = input().split()
    alphabet = {'A': 10, 'B': 11, 'C': 12, 'D': 13, 'E': 14, 'F': 15}
    if alphabet.get(a) < alphabet.get(b):
        print('<')
    elif alphabet.get(a) > alphabet.get(b):
        print('>')
    else:
        print('=') 
main()
