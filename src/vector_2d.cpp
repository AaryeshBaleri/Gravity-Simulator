#include "vector_2d.hpp"

Vector2D::Vector2D() {
    _x = 0.0f;
    _y = 0.0f;
}

Vector2D::Vector2D(float x, float y) {
    _x = x;
    _y = y;
}

Vector2D& Vector2D::add(const Vector2D& vec) {
    _x += vec._x;
    _y += vec._y;
    return *this;
}

Vector2D& Vector2D::subtract(const Vector2D& vec) {
    _x -= vec._x;
    _y -= vec._y;
    return *this;
}

Vector2D& Vector2D::multiply(const Vector2D& vec) {
    _x *= vec._x;
    _y *= vec._y;
    return *this;
}

Vector2D& Vector2D::divide(const Vector2D& vec) {
    _x /= vec._x;
    _y /= vec._y;
    return *this;
}

Vector2D& operator+(Vector2D& v1, Vector2D& v2) {
    return v1.add(v2);
}

Vector2D& operator-(Vector2D& v1, Vector2D& v2) {
    return v1.subtract(v2);
}

Vector2D& operator*(Vector2D& v1, Vector2D& v2) {
    return v1.multiply(v2);
}

Vector2D& operator/(Vector2D& v1, Vector2D& v2) {
    return v1.divide(v2);
}

Vector2D& Vector2D::operator+=(const Vector2D& vec) {
    return this->add(vec);
}

Vector2D& Vector2D::operator-=(const Vector2D& vec) {
    return this->subtract(vec);
}

Vector2D& Vector2D::operator*=(const Vector2D& vec) {
    return this->multiply(vec);
}

Vector2D& Vector2D::operator/=(const Vector2D& vec) {
    return this->divide(vec);
}

std::ostream& operator<<(std::ostream& stream, const Vector2D& vec) {
    stream << "(" << vec._x << ", " << vec._y << ")";
    return stream;
}