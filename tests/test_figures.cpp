#include <gtest/gtest.h>
#include <sstream>
#include "Square.h"
#include "Rectangle.h"
#include "Trapezoid.h"
#include "Array.h"

TEST(SquareTest, DefaultCtor) {
    Square s;
    EXPECT_DOUBLE_EQ(static_cast<double>(s), 0);
    Point c = s.center();
    EXPECT_DOUBLE_EQ(c.x, 0);
    EXPECT_DOUBLE_EQ(c.y, 0);
}

TEST(SquareTest, ParamCtor) {
    Square s(Point(1, 2), 4);
    EXPECT_DOUBLE_EQ(static_cast<double>(s), 16);
    Point c = s.center();
    EXPECT_DOUBLE_EQ(c.x, 1);
    EXPECT_DOUBLE_EQ(c.y, 2);
}

TEST(SquareTest, InvalidSide) {
    EXPECT_THROW(Square(Point(0, 0), -5), std::invalid_argument);
}

TEST(SquareTest, CopyCtor) {
    Square s1(Point(1, 1), 3);
    Square s2(s1);
    EXPECT_TRUE(s1 == s2);
}

TEST(SquareTest, MoveCtor) {
    Square s1(Point(1, 1), 3);
    double area = static_cast<double>(s1);
    Square s2(std::move(s1));
    EXPECT_DOUBLE_EQ(static_cast<double>(s2), area);
}

TEST(SquareTest, CopyAssign) {
    Square s1(Point(1, 1), 3);
    Square s2;
    s2 = s1;
    EXPECT_TRUE(s1 == s2);
}

TEST(SquareTest, ReadWrite) {
    Square s;
    std::istringstream is("5 5 10");
    is >> s;
    EXPECT_DOUBLE_EQ(static_cast<double>(s), 100);
    std::ostringstream os;
    os << s;
    EXPECT_FALSE(os.str().empty());
}

TEST(RectangleTest, DefaultCtor) {
    Rectangle r;
    EXPECT_DOUBLE_EQ(static_cast<double>(r), 0);
}

TEST(RectangleTest, ParamCtor) {
    Rectangle r(Point(0, 0), 4, 5);
    EXPECT_DOUBLE_EQ(static_cast<double>(r), 20);
}

TEST(RectangleTest, InvalidSize) {
    EXPECT_THROW(Rectangle(Point(0, 0), -1, 5), std::invalid_argument);
}

TEST(RectangleTest, CopyCtor) {
    Rectangle r1(Point(1, 1), 3, 4);
    Rectangle r2(r1);
    EXPECT_TRUE(r1 == r2);
}

TEST(RectangleTest, ReadWrite) {
    Rectangle r;
    std::istringstream is("0 0 6 8");
    is >> r;
    EXPECT_DOUBLE_EQ(static_cast<double>(r), 48);
}

TEST(TrapezoidTest, DefaultCtor) {
    Trapezoid t;
    EXPECT_DOUBLE_EQ(static_cast<double>(t), 0);
}

TEST(TrapezoidTest, ParamCtor) {
    Trapezoid t(Point(0, 0), 4, 6, 5);
    EXPECT_DOUBLE_EQ(static_cast<double>(t), 25);
}

TEST(TrapezoidTest, InvalidSize) {
    EXPECT_THROW(Trapezoid(Point(0, 0), -1, 6, 5), std::invalid_argument);
}

TEST(TrapezoidTest, CopyCtor) {
    Trapezoid t1(Point(1, 1), 3, 5, 4);
    Trapezoid t2(t1);
    EXPECT_TRUE(t1 == t2);
}

TEST(TrapezoidTest, ReadWrite) {
    Trapezoid t;
    std::istringstream is("0 0 2 4 3");
    is >> t;
    EXPECT_DOUBLE_EQ(static_cast<double>(t), 9);
}

TEST(ArrayTest, AddAndSize) {
    Array arr;
    EXPECT_EQ(arr.size(), 0);
    arr.add(new Square(Point(0, 0), 2));
    EXPECT_EQ(arr.size(), 1);
    arr.add(new Rectangle(Point(0, 0), 3, 4));
    EXPECT_EQ(arr.size(), 2);
}

TEST(ArrayTest, Remove) {
    Array arr;
    arr.add(new Square(Point(0, 0), 2));
    arr.add(new Rectangle(Point(0, 0), 3, 4));
    arr.remove(0);
    EXPECT_EQ(arr.size(), 1);
}

TEST(ArrayTest, RemoveOutOfRange) {
    Array arr;
    arr.add(new Square(Point(0, 0), 2));
    EXPECT_THROW(arr.remove(5), std::out_of_range);
}

TEST(ArrayTest, TotalArea) {
    Array arr;
    arr.add(new Square(Point(0, 0), 2));
    arr.add(new Rectangle(Point(0, 0), 3, 4));
    EXPECT_DOUBLE_EQ(arr.totalArea(), 4 + 12);
}

TEST(ArrayTest, Get) {
    Array arr;
    arr.add(new Square(Point(0, 0), 5));
    Figure* f = arr.get(0);
    EXPECT_DOUBLE_EQ(static_cast<double>(*f), 25);
}

TEST(ArrayTest, GetOutOfRange) {
    Array arr;
    EXPECT_THROW(arr.get(0), std::out_of_range);
}

TEST(ArrayTest, CopyCtor) {
    Array arr1;
    arr1.add(new Square(Point(0, 0), 3));
    Array arr2(arr1);
    EXPECT_EQ(arr2.size(), 1);
    EXPECT_DOUBLE_EQ(arr2.totalArea(), 9);
}

TEST(ArrayTest, MoveAssign) {
    Array arr1;
    arr1.add(new Square(Point(0, 0), 4));
    Array arr2;
    arr2 = std::move(arr1);
    EXPECT_EQ(arr2.size(), 1);
    EXPECT_DOUBLE_EQ(arr2.totalArea(), 16);
}

TEST(ArrayTest, PrintAll) {
    Array arr;
    arr.add(new Square(Point(1, 1), 2));
    std::ostringstream os;
    arr.printAll(os);
    EXPECT_FALSE(os.str().empty());
}

TEST(FigureTest, Clone) {
    Square s(Point(1, 1), 5);
    Figure* f = s.clone();
    EXPECT_TRUE(s.equals(*f));
    delete f;
}

TEST(FigureTest, Equals) {
    Square s1(Point(1, 1), 5);
    Square s2(Point(1, 1), 5);
    Rectangle r(Point(1, 1), 5, 5);
    EXPECT_TRUE(s1.equals(s2));
    EXPECT_FALSE(s1.equals(r));
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
