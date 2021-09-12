#include <cstdint>

class RGBA {
public:
	RGBA(uint8_t red = 0, uint8_t green = 0, uint8_t blue = 0, uint8_t alpha = 255) : 
		m_red(red), m_green(green), m_blue(blue), m_alpha(alpha) {}
	
	void print() { 
		printf("Red: %d Green: %d Blue: %d Alpha: %d\n", m_red, m_green, m_blue, m_alpha);
	}
	
private:
	uint8_t m_red;
	uint8_t m_green;
	uint8_t m_blue;
	uint8_t m_alpha;
};