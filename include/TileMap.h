#ifndef TILEMAP_H
#define TILEMAP_H

#include <string>
#include <vector>
#include <memory>
#include <Component.h>
#include <TileSet.h>

class TileMap : public Component {
    public:
        TileMap(GameObject& associated, std::string file, TileSet* tileSet);

        void load(std::string file);
        void setTileSet(TileSet* tileSet);
        int& at(int x, int y, int z = 0);

        void render() override;
        void renderLayer(int layer);
        void update(float dt) override;

        int  getWidth();
        int  getHeight();
        int  getDepth();

    private:
        std::vector<int>         tileMatrix;
        std::unique_ptr<TileSet> tileSet;
        int mapWidth;
        int mapHeight;
        int mapDepth;
};

#endif
