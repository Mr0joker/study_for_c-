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
    Color();
    Color(int r, int g, int b);
    Color(int r, int g, int b, int a );

    int value() const;
    void setColor(int r, int g, int b, int a = 0);

    ~Color(){}
};

#endif // COLOR_HPP