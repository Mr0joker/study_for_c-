#ifndef COLOR_HPP
#define COLOR_HPP

class Color
{

private:
    int m_red;
    int m_green;
    int m_blue;
    int m_alpha;

public:
    Color(int r = 0, int g = 0, int b = 0) : m_red(r), m_green(g), m_blue(b) {}
    int value() const;
    void setColor(int r, int g, int b, int a = 0);
};

#endif // COLOR_HPP