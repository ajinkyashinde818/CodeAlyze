import math

def answerCounter(N, i, answer):
    counter = 0
    power = 2
    sumPower = 1

    while N % i == 0:
        counter = counter + 1

        if sumPower == counter:
            answer = answer + 1
            sumPower = sumPower + power
            power = power + 1

        N = N // i

    return answer, N

def main():
    N = int(input())

    answer, N = answerCounter(N, 2, 0)

    for i in range(3, int(math.sqrt(N)) + 1, 2):
        answer, N = answerCounter(N, i, answer)

        if N < i:
            break

    if N > 2:
        answer, N = answerCounter(N, N, answer)

    print(answer)

if __name__ == "__main__":
    main()
