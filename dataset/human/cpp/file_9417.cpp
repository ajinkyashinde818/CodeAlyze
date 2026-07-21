#include <bits/stdc++.h>
using namespace std;

bool is_same_image(vector<string> &image_a, vector<string> &image_b, int a_h, int a_w)
{
  for (int b_h = 0; b_h < image_b.size(); b_h++)
  {
    for (int b_w = 0; b_w < image_b.size(); b_w++)
    {
      if (image_a.at(a_h + b_h).at(a_w + b_w) != image_b.at(b_h).at(b_w))
      {
        return false;
      }
    }
  }
  return true;
}

int main()
{
  int len_a, len_b;
  cin >> len_a >> len_b;

  vector<string> image_a(len_a);
  vector<string> image_b(len_b);

  for (int i = 0; i < len_a; i++)
  {
    cin >> image_a.at(i);
  }
  for (int i = 0; i < len_b; i++)
  {
    cin >> image_b.at(i);
  }

  for (int h = 0; h < len_a - len_b + 1; h++)
  {
    for (int w = 0; w < len_a - len_b + 1; w++)
    {
      if (is_same_image(image_a, image_b, h, w))
      {
        cout << "Yes" << endl;
        exit(0);
      }
    }
  }
  cout << "No" << endl;
}
