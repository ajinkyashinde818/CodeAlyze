def main():
    text = input()
    words = ['dreamer', 'eraser', 'dream', 'erase']
    length = len(text)
    while text:
        for word in words:
            if text.endswith(word):
                text = text[:-len(word)]
        else:
            if (new := len(text)) != length:
                length = new
            else:
                return 'NO'
    return 'YES'


if __name__ == '__main__':
    ans = main()
    print(ans)
