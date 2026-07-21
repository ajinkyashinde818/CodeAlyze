#include <iostream>
#include <bitset>
#include <string>

class MonochromeImage{
public:
	static constexpr std::size_t MaxSize{50};

private:
	using DataType = std::bitset<MaxSize * MaxSize>;

public:
	MonochromeImage(std::size_t size) : m_size{size}, m_valid{}, m_data{} {}

	void set(std::size_t x, std::size_t y, bool value = true) {
		m_valid.set(index(x, y));
		m_data.set(index(x, y), value);
	}
	void reset(std::size_t x, std::size_t y) {
		m_valid.reset(index(x, y));
		m_data.reset(index(x, y));
	}

	std::size_t size() const { return m_size; }
	DataType valid() const { return m_valid; }
	DataType data() const { return m_data; }
	DataType valid_data() const { return (m_data & m_valid); }

	bool is_including(const MonochromeImage& image) {
		if (m_size < image.size()) { return false; }
		for (std::size_t i = 0; i <= (m_size - image.size()); i++) {
			for (std::size_t j = 0; j <= (m_size - image.size()); j++) {
				std::size_t offset = index(i, j);
				if ((valid_data() & (image.valid() << offset))
							== (image.valid_data() << offset)) {
					return true;
				}
			}
		}
		return false;
	}

private:
	static constexpr std::size_t index(std::size_t x, std::size_t y) {
		return x * MaxSize + y;
	}

	std::size_t m_size;
	DataType m_valid;
	DataType m_data;
};

inline std::istream& operator>>(std::istream& is, MonochromeImage& image) {
	for (std::size_t i = 0; i < image.size(); i++) {
		std::string buffer;
		is >> buffer;
		for (std::size_t j = 0; j < image.size(); j++) {
			switch (buffer.at(j)) {
			case '#' : image.set(i, j, true); break;
			case '.' : image.set(i, j, false); break;
			default  : std::cerr << "ERROR: no matching image color!" << std::endl; break;
			}
		}
	}
	return is;
}

int main()
{
	std::size_t a_size, b_size;
	std::cin >> a_size >> b_size;
	
	MonochromeImage a{a_size};
	MonochromeImage b{b_size};

	std::cin >> a >> b;

	if (a.is_including(b)) {
		std::cout << "Yes" << std::endl;
	} else {
		std::cout << "No" << std::endl;
	}

	return 0;
}
