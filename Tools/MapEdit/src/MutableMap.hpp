#ifndef MUTABLEMAP_HPP
#define MUTABLEMAP_HPP

#include <QString>
#include <Map.hpp>

class MutableMap : public Engine::Map
{
public:
    MutableMap();
    MutableMap(QString filename);

    void setObstacle(unsigned _x, unsigned _y,bool newVal);
    void toggle(unsigned _x, unsigned _y);

    QString getFilename(void);
    void saveToFile(QString filename);
    void printMap(void);
protected:
    QString fname;
};

#endif // MUTABLEMAP_HPP
