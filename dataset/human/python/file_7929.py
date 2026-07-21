import sys

def get_read_func(fileobject):
    if fileobject == None :
        return raw_input
    else:
        return fileobject.readline

def main():
    if len(sys.argv) > 1:
        f = open(sys.argv[1])
    else:
        f = None
    read_func = get_read_func(f);
    S = read_func().strip()
    if S[0] != S[1] and S[1] != S[2] and S[0] != S[2]:
        print 'Yes'
    else:
        print 'No'

if __name__ == '__main__':
    main()
