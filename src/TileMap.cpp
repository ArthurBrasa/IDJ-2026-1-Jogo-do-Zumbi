#include <TileMap.h>
#include <GameObject.h>
#include <cstdio>
#include <iostream>

TileMap::TileMap(GameObject& associated, std::string file, TileSet* tileSet)
    : Component(associated), tileSet(tileSet), mapWidth(0), mapHeight(0), mapDepth(0) {
    load(file);
}

void TileMap::load(std::string file) {
    FILE* fp = fopen(file.c_str(), "r");
    if (!fp) {
        std::cout << "Failed to open map file: " << file << std::endl;
        return;
    }

    if (fscanf(fp, "%d,%d,%d,", &mapWidth, &mapHeight, &mapDepth) != 3) {
        std::cout << "Failed to read map dimensions: " << file << std::endl;
        fclose(fp);
        return;
    }

    int total = mapWidth * mapHeight * mapDepth;
    tileMatrix.resize(total);

    for (int i = 0; i < total; ++i) {
        int value = 0;
        if (fscanf(fp, "%d,", &value) != 1) {
            std::cout << "Failed to read tile at index " << i << std::endl;
            break;
        }
        tileMatrix[i] = value;
    }

    fclose(fp);
}

void TileMap::setTileSet(TileSet* tileSet) {
    this->tileSet.reset(tileSet);
}

int& TileMap::at(int x, int y, int z) {
    return tileMatrix[z * mapWidth * mapHeight + y * mapWidth + x];
}

void TileMap::render() {
    for (int z = 0; z < mapDepth; ++z) {
        renderLayer(z);
    }
}

void TileMap::renderLayer(int layer) {
    if (!tileSet) {
        return;
    }

    int tw = tileSet->getTileWidth();
    int th = tileSet->getTileHeight();

    for (int y = 0; y < mapHeight; ++y) {
        for (int x = 0; x < mapWidth; ++x) {
            int index = at(x, y, layer);
            if (index < 0) {
                continue;
            }
            float px = associated.box.x + x * tw;
            float py = associated.box.y + y * th;
            tileSet->renderTile((unsigned)index, px, py);
        }
    }
}

void TileMap::update(float dt) {
    (void)dt;
}

int TileMap::getWidth()  { return mapWidth; }
int TileMap::getHeight() { return mapHeight; }
int TileMap::getDepth()  { return mapDepth; }
