#include <QDebug>

template <typename T>
std::string toString(const T& value)
{
    std::stringstream stream;
    stream << value;
    return stream.str();
}

template <typename T>
void tellMeVector(const T& value)
{
    qDebug() << "tellMe Vector // X= " << value.x <<
                " Y= " << value.y;
}

template <typename T>
void tellMeRect(const T& value)
{
    qDebug() << "tellMe Rect // L = " << value.left <<
                " T = " << value.top <<
                " W = " << value.width <<
                " H = " << value.height;
}
