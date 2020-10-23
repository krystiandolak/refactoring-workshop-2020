#pragma once

class SnakeMap {
public:
    SnakeMap();
    void setWidth(int width);
    void setHeight(int height);
    int getWidth() const;
    int getHeight() const;
private:
    int m_width;
    int m_height;
};