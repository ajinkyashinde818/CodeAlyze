#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>


int
main()
{
  std::cin.tie(nullptr);
  std::ios::sync_with_stdio(false);

  int n, m;
  std::cin >> n >> m;

  std::vector<std::string> image(n, std::string());
  for (auto&& row : image) {
    std::cin >> row;
  }

  std::vector<std::string> templateImage(m, std::string());
  for (auto&& row : templateImage) {
    std::cin >> row;
  }

  for (int i = 0, im = n - m + 1; i < im; i++) {
    for (int j = 0, jm = n - m + 1; j < jm; j++) {
      bool isDiffer = false;
      for (int k = 0; k < m; k++) {
        for (int l = 0; l < m; l++) {
          if (image[i + k][j + l] != templateImage[k][l]) {
            isDiffer = true;
            break;
          }
        }
      }
      if (!isDiffer) {
        std::cout << "Yes" << std::endl;
        return EXIT_SUCCESS;
      }
    }
  }
  std::cout << "No" << std::endl;

  return EXIT_SUCCESS;
}
