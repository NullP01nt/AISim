#include <Engine/Map.hpp>

Engine::Map::Map(void) : width(64), height(32)
{
    initDefault();
}

Engine::Map::Map(int _width, int _height) : width(_width), height(_height) {
    initDefault();
}

Engine::Map::Map(const QString& filename) {
    unsigned count=0;
    unsigned char cur_data=0;
    unsigned char d_mask=0x80;

    QFile mapFile(filename);
    if(mapFile.open(QIODevice::ReadOnly)) {
        QByteArray binblob = mapFile.readAll();
        map_hdr_t* m = reinterpret_cast<map_hdr_t*>(binblob.data());
        if(strcmp("MAP",m->magic)==0) {
            data = QVector<bool>();
            width = (unsigned int)(m->width);
            height = (unsigned int)(m->height);
            for(int i=sizeof(map_hdr_t);i<binblob.size();i++) {
                d_mask=0x80;
                cur_data = binblob.at(i);
                while(d_mask>=1) {
                    data.push_back(cur_data&d_mask);
                    d_mask >>= 1;
                    count++;
                }
            }
            while(count<(width*height)) {
                data.push_back(false);
                count++;
            }
        } else {
            initDefault();
        }
    } else {
        initDefault();
    }
}

Engine::Map::~Map(void) {
    data.clear();
}

void Engine::Map::initDefault(void) {
    data = QVector<bool>();
    for(unsigned i=0; i<(width*height);i++)
        data.push_back(false);
}

bool Engine::Map::isOutbound(unsigned _x, unsigned _y) {
    return (_x>=width || _y>=height);
}

bool Engine::Map::isObstacle(unsigned _x, unsigned _y) {
    return data.at((_y*width)+_x);
}

unsigned Engine::Map::getWidth(void) { return width; }
unsigned Engine::Map::getHeight(void) { return height; }
unsigned Engine::Map::getSize(void) { return width*height; }
