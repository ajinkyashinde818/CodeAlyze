#include <iostream>
#include <cstring>
using namespace std;
int N;
long long L;
char Str[100005];
int len;
long long cnt;
struct Trie{
int ap;
Trie * next[2];
Trie()
{
    ap = 0;
    next[0] = NULL;
    next[1] = NULL;
}
};
Trie * Root = new Trie;
void insert(Trie * node, int pos)
{
    if(pos == len + 1)
    {
        node -> ap = 1;
        return;
    }
    int dig = Str[pos] - '0';
    if(node -> next[dig] == NULL)
    {
        node -> next[dig] = new Trie;
    }
    insert(node -> next[dig], pos + 1);
}

void Count(Trie * node, int lv)
{
    if(node -> next[0] == NULL && node -> next[1] == NULL)
        return;
    for(int i = 0; i < 2; i++)
    {

        if(node -> next[i] == NULL)
        {
            long long nb = L - lv;
            int aux = 0;
            while(nb % 2 == 0)
            {
                aux++;
                nb /= 2;
            }
            cnt ^= (1LL << aux);
        }
        else
            Count(node -> next[i], lv + 1);
    }
}

void Read()
{
    cin >> N >> L;
    cin.get();
    for(int i = 1; i <= N; i++)
    {
        cin.getline(Str + 1, 100005);
        len = strlen(Str + 1);
        insert(Root, 1);

    }
}
int main()
{
    Read();
    Count(Root, 0);
    if(cnt == 0)
    {
        cout << "Bob\n";
    }
    else
        cout << "Alice\n";
    return 0;
}
