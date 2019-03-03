#include "TileMap.h"


bool TileMap::load (const  std::string& tileset, sf::Vector2u tilesize, const int* tiles, unsigned int width, unsigned int height)
{
    // Load tileset texture
    if (!m_tileset.loadFromFile(tileset))
        return false;

    // resize the vertex to fit the level
    m_vertices.setPrimitiveType(sf::Quads);
    m_vertices.resize(width*height*4);

    //populate the vertex array, one quad per tile
    for (unsigned int i = 0; i < width; i++)
    {
        for (unsigned int j = 0; j < height; j++)
        {
            //finds current tile
            int tileNumber = tiles[i + j * width];

            // find position in tileset texture
            int tu = tileNumber % (m_tileset.getSize().x / tilesize.x);
            int tv = tileNumber / (m_tileset.getSize().x / tilesize.x);

            //creates pointer to current tile quad
            sf::Vertex* quad = &m_vertices[(i + j * width) * 4];

            //define quads corners
            quad[0].position = sf::Vector2f(i * tilesize.x, j * tilesize.y);
            quad[1].position = sf::Vector2f((i + 1) * tilesize.x, j * tilesize.y);
            quad[2].position = sf::Vector2f((i + 1) * tilesize.x, (j + 1) * tilesize.y);
            quad[3].position = sf::Vector2f(i * tilesize.x, (j + 1) * tilesize.y);

            //define texture coordinates
            quad[0].texCoords = sf::Vector2f(tu * tilesize.x, tv * tilesize.y);
            quad[1].texCoords = sf::Vector2f((tu + 1) * tilesize.x, tv * tilesize.y);
            quad[2].texCoords = sf::Vector2f((tu + 1) * tilesize.x, (tv + 1) * tilesize.y);
            quad[3].texCoords = sf::Vector2f(tu * tilesize.x, (tv + 1) * tilesize.y);
        }
    }

    return true;
}

void TileMap::draw (sf::RenderTarget& target, sf::RenderStates states) const
{
    //apply transform
    states.transform *= getTransform();

    //apply tileset
    states.texture = &m_tileset;

    //draw vertex array
    target.draw(m_vertices, states);
}
