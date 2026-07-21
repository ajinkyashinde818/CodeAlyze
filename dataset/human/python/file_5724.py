from collections import deque


def main():
    string = deque(input())
    answer = 0
    while string:
        if string[0] == string[-1]:
            string.pop()
            if string:
                string.popleft()
            answer += 0
        else:
            if string[0] == "x":
                string.append("x")
                answer += 1
            elif string[-1] == "x":
                string.appendleft("x")
                answer += 1
            else:
                answer = -1
                break
    print(answer)


if __name__ == '__main__':
    main()
