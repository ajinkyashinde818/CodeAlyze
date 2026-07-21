def main():
    img_a_row, img_b_row = map(int, input().split())
    img_a = [input() for _ in range(img_a_row)]
    img_b = [input() for _ in range(img_b_row)]
    answer = False
    for i in range(img_a_row - img_b_row + 1):
        for j in range(img_a_row - img_b_row + 1):
            count = 0
            for k in range(img_b_row):
                if img_a[i + k][j:j+img_b_row] == img_b[k]:
                    count += 1
            if count == img_b_row:
                answer = True
    print("Yes" if answer else "No")


if __name__ == '__main__':
    main()
