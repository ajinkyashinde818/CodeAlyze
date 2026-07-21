#include <cstdio>
#include <vector>
#include <queue>

int main(void)
{

    int N;
    scanf("%d", &N);

    std::vector<int> A, B;
    std::queue<int> skipped, answer1, answer2;
    int x;
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &x);
        A.push_back(x);
    }
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &x);
        B.push_back(x);
    }

    for (int i = 0, j = N - 1; i < N; i++)
    {
        while (j >= 0 && B[j] == A[i])
        {
            skipped.push(B[j]);
            j--;
        }
        if (j < 0)
        {
            if (skipped.front() != A[i])
            {
                answer1.push(skipped.front());
                skipped.pop();
                continue;
            }
            else
            {
                break;
            }
        }
        answer1.push(B[j]);
        j--;
    }
    while(!skipped.empty()){
        skipped.pop();
    }
    for (int i = 0, j = 0; i < N; i++)
    {
        while (j < N && B[j] == A[i])
        {
            skipped.push(B[j]);
            j++;
        }
        if (j == N)
        {
            if (skipped.front() != A[i])
            {
                answer2.push(skipped.front());
                skipped.pop();
                continue;
            }
            else
            {
                break;
            }
        }
        answer2.push(B[j]);
        j++;
    }

    if (answer1.size() != N && answer2.size() != N)
    {
        printf("No\n");
    }
    else if (answer1.size() == N)
    {
        printf("Yes\n");
        while (!answer1.empty())
        {
            printf("%d ", answer1.front());
            answer1.pop();
        }
    }
    else
    {
        printf("Yes\n");
        while (!answer2.empty())
        {
            printf("%d ", answer2.front());
            answer2.pop();
        }
    }

    return 0;
}
