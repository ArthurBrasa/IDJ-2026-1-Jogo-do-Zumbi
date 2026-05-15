#include <TileSet.h>

TileSet::TileSet(int tileWidth, int tileHeight, std::string file)
    : tileSet(file), tileWidth(tileWidth), tileHeight(tileHeight), tileCount(0) {
    if (tileSet.isOpen()) {
        int columns = tileSet.getWidth() / tileWidth;
        int rows    = tileSet.getHeight() / tileHeight;
        tileCount   = columns * rows;
        tileSet.setFrameCount(columns, rows);
    }
}

void TileSet::renderTile(unsigned index, float x, float y) {
    if ((int)index >= tileCount) {
        return;
    }
    tileSet.setFrame((int)index);
    tileSet.render((int)x, (int)y, tileWidth, tileHeight);
}

int TileSet::getTileWidth() {
    return tileWidth;
}

int TileSet::getTileHeight() {
    return tileHeight;
}
