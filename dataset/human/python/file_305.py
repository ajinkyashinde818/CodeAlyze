from sys import stdin


def main():
    _ = int(stdin.readline().rstrip())
    As = [int(x) for x in stdin.readline().rstrip().split()]
    mcount = len([x for x in As if x < 0])
    if mcount % 2 == 0:
        print(sum([abs(x) for x in As]))
    else:
        min_ = min([abs(x) for x in As])
        sum_ = sum([abs(x) for x in As])
        print(sum_ - (min_ * 2))


if __name__ == "__main__":
    main()
