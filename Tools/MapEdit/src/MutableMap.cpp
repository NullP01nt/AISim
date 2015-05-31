#include "MutableMap.hpp"

#include <Map.hpp>

#include <QTextStream>
#define cout QTextStream(stdout)
#define endl '\n'

MutableMap::MutableMap() : Map(), fname() { }
MutableMap::MutableMap(QString filename) : Map(filename), fname(filename) { }

void MutableMap::setObstacle(unsigned _x, unsigned _y, bool newVal) {
    if(!(isOutbound(_x,_y))) {
        data.replace((_y*width)+_x,newVal);
    }
}

void MutableMap::toggle(unsigned _x, unsigned _y) {
    setObstacle(_x,_y,isObstacle(_x,_y)?false:true);
}

QString MutableMap::getFilename(void) {
    return fname;
}

void MutableMap::saveToFile(QString filename) {
    int count=0;
    char cur_data=0;
    unsigned char d_mask=0x80;

    QByteArray binblob = QByteArray();
    const char hdr[16] = {'M','A','P',0x00,0x40,0x20,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};
    for(unsigned i=0; i<16; i++) {
        binblob.push_back(hdr[i]);
    }

    while(count < data.size()) {
        d_mask=0x80;
        cur_data=0x00;
        while(d_mask>=0x01) {
            if(data.at(count))
                cur_data |= d_mask;
            d_mask >>= 1;
            count++;
        }
        binblob.push_back(cur_data);
    }

    QFile mf(filename);
    if(mf.open(QIODevice::WriteOnly)) {
        mf.write(binblob);
    }
}

void MutableMap::printMap(void) {
    for(int i=0; i<data.size(); i++) {
        if(i%width==0) cout << endl;
        cout << (data.at(i) ? "1":"0");
    }
}
