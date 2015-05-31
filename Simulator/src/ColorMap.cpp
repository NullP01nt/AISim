#include "ColorMap.hpp"

#include <random>
#include <QTime>
#include <QColor>

const float ColorMap::goldenratio = 0.618033988749895;

ColorMap::ColorMap(){
    QTime t = QTime::currentTime();
    qsrand(t.msec());
    h = (qrand()%256);
    map = QMap<unsigned int, QColor>();
}

QColor ColorMap::getColor(unsigned index) {
    if (map.keys().contains(index)) {
        return map[index];
    }
    generateColor(index);
    return map[index];
}

void ColorMap::generateColor(unsigned index) {
    h+=(goldenratio*256);
    h = h%256;
    map.insert(index,QColor::fromHsv(h,128,243));
}
