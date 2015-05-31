#ifndef COLORMAP_HPP
#define COLORMAP_HPP

#include <QMap>
#include <QColor>

class ColorMap
{
public:
    ColorMap();

    QColor getColor(unsigned index);
private:
    void generateColor(unsigned index);
    unsigned char h;
    static const float goldenratio;
    QMap<unsigned int, QColor> map;
};

#endif // COLORMAP_HPP
