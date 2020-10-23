#include "SnakeMap.hpp"

SnakeMap::SnakeMap() : m_width(0), m_height(0){};

void SnakeMap::setWidth(int width) {
    m_width = width;
};

void SnakeMap::setHeight(int height) {
    m_height = height;
};

int SnakeMap::getWidth() const {
    return m_width;
};

int SnakeMap::getHeight() const{
    return m_height;
};