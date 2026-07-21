#include <bits/stdc++.h>

int main(int argc, char *argv[]) {
	std::vector<std::string> image_a;
	std::vector<std::string> template_image_b;

	int image_a_size = 0;
	int template_image_b_size = 0;
	std::cin >> image_a_size;
	std::cin >> template_image_b_size;

	std::string current_str;
	for (int i = 0; i < image_a_size; i++) {
		std::cin >> current_str;
		image_a.push_back(current_str);
	}
	for (int j = 0; j < template_image_b_size; j++) {
		std::cin >> current_str;
		template_image_b.push_back(current_str);
	}

	bool found = false;
	for (int k = 0; k < image_a_size - template_image_b_size + 1; k++) {  // 平行移動
		std::string::size_type base_pos = 0;
		int find_count = 0;
		for (int l = 0; l < template_image_b_size; l++) {
			std::string::size_type pos = image_a[k + l].find(template_image_b[l], base_pos);
			if (pos != std::string::npos) {
				base_pos = pos;	  // 見つかったら、そこを基準とする
				find_count++;
			}
		}
		if (find_count == template_image_b_size) {
			found = true;
			break;
		}
	}

	std::cout << ((found) ? "Yes" : "No") << std::endl;
	return 0;
}
