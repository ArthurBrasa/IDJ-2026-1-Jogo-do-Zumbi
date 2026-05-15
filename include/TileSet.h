#ifndef TILESET_H
#define TILESET_H

#include <string>
#include <Sprite.h>

class TileSet {
    public:
        TileSet(int tileWidth, int tileHeight, std::string file);

        void renderTile(unsigned index, float x, float y);
        int  getTileWidth();
        int  getTileHeight();

    private:
        Sprite  tileSet;
        int     tileWidth;
        int     tileHeight;
        int     tileCount;
};

#endif
