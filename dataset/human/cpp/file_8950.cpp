#include <vector>
#include <iostream>
#include <string>
class Image {
	enum Color : char {
		Black = '#', White = '.'
	};
public:
	Image(int n, std::istream &is);
	bool include_image(const Image &other) const;
private:
	std::vector<std::vector<Color>> color;
	Color at(int x, int y) const;
	int size() const;
	bool search_with_offset(int ox, int oy, const Image &other) const;
	void show() const;
};

Image::Image(int n, std::istream & is) :color(n, std::vector<Color>(n))
{
	for (std::string str; --n >= 0 && std::cin >> str; ) {
		for (auto i = 0; i < str.size(); ++i) {
			if (str[i] == '#') color[n][i] = Black;
			else color[n][i] = White;
		}
	}
}

bool Image::include_image(const Image & other) const
{
	for (auto ox = 0; ox <= size() - other.size(); ++ox) {
		for (auto oy = 0; oy <= size() - other.size(); ++oy) {
			if (search_with_offset(ox, oy, other)) return true;
		}
	}
	return false;
}

Image::Color Image::at(int x, int y) const
{
	return color[x][y];
}

int Image::size() const
{
	return color.size();
}

bool Image::search_with_offset(int ox, int oy, const Image & other) const
{
	for (auto x = 0; x < other.size(); ++x) {
		for (auto y = 0; y < other.size(); ++y) {
			if (at(ox + x, oy + y) != other.at(x, y)) return false;
		}
	}
	return true;
}

void Image::show() const
{
	for (const auto &line : color) {
		for (const auto &cell : line) {

			std::cout << static_cast<char>(cell);
		}
		std::cout << '\n';
	}
}

int main() {
	int n, m;
	std::cin >> n >> m;
	Image a(n, std::cin);
	Image b(m, std::cin);
	if (a.include_image(b)) std::cout << "Yes\n";
	else std::cout << "No\n";
	return 0;
}
