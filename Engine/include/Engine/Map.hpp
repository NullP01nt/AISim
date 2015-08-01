#ifndef MAP_HPP
#define MAP_HPP

#include <QVector>
#include <QString>
#include <QFile>

namespace Engine {

class Map
{
    struct map_hdr_t {
        char magic[4];
        unsigned char width;
        unsigned char height;
        char reserved[10];
    };
public:
    Map(void);
    Map(int _width, int _height);
    Map(const QString& filename);
    ~Map(void);

    bool isOutbound(unsigned _x, unsigned _y);
    bool isObstacle(unsigned _x, unsigned _y);

    unsigned getWidth(void);
    unsigned getHeight(void);
    unsigned getSize(void);
protected:
    unsigned width;
    unsigned height;
    QVector<bool> data;

    void initDefault(void);
};
}
#endif // MAP_HPP
