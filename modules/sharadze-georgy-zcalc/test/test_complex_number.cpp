// Copyright 2016 Sharadze Georgy

#include "include/complex_number.h"
#include "gtest/gtest.h"

TEST(Sharadze_Georgy_ComplexNumberTest,
     Can_Create_Complex_Number_Without_Param) {
    // Arrange
    const ComplexNumber z;

    // Assert & Act
    EXPECT_DOUBLE_EQ(z.getRe(), z.getIm());
}

TEST(Sharadze_Georgy_ComplexNumberTest, Can_Create_Complex_Number_With_Param) {
    // Arrange & Act
    const ComplexNumber z(0.1, 0.1);

    // Assert
    EXPECT_DOUBLE_EQ(z.getRe(), z.getIm());
}

TEST(Sharadze_Georgy_ComplexNumberTest, Can_Create_Complex_Number_With_Copy) {
    // Arrange
    const ComplexNumber z1(2.1, 2.3);

    // Act
    const ComplexNumber z2(z1);

    // Assert
    EXPECT_TRUE(z1 == z2);
}

TEST(Sharadze_Georgy_ComplexNumberTest, Can_Get_Fields_Correctly) {
    // Arrange
    const double _re = 5.0;
    const double _im = 5.1;
    const ComplexNumber z(_re, _im);

    // Act & Assert
    EXPECT_DOUBLE_EQ(_re, z.getRe());
    EXPECT_DOUBLE_EQ(_im, z.getIm());
}

TEST(Sharadze_Georgy_ComplexNumberTest, Can_Set_Fields_Correctly) {
    // Arrange
    const double _re = 5.0;
    const double _im = 5.1;
    ComplexNumber z;

    // Act
    z.setRe(_re);
    z.setIm(_im);

    // Assert
    EXPECT_DOUBLE_EQ(_re, z.getRe());
    EXPECT_DOUBLE_EQ(_im, z.getIm());
}

TEST(Sharadze_Georgy_ComplexNumberTest, Can_Do_Sum_Correcty) {
    // Arrange
    const double _re1 = 5.0;
    const double _im1 = 5.1;
    const double _re2 = 5.0;
    const double _im2 = 4.9;
    const ComplexNumber z1(_re1, _im1);
    const ComplexNumber z2(_re2, _im2);

    // Act
    ComplexNumber actual = z1 + z2;

    // Assert
    ComplexNumber expected(_re1 + _re2, _im1 + _im2);
    EXPECT_TRUE(actual == expected);
}

TEST(Sharadze_Georgy_ComplexNumberTest, Can_Do_Subtraction_Correctly) {
    // Arrange
    const double _re1 = 5.0;
    const double _im1 = 5.1;
    const double _re2 = 5.0;
    const double _im2 = 4.9;
    const ComplexNumber z1(_re1, _im1);
    const ComplexNumber z2(_re2, _im2);

    // Act
    ComplexNumber actual = z1 - z2;

    // Assert
    ComplexNumber expected(_re1 - _re2, _im1 - _im2);
    EXPECT_TRUE(actual == expected);
}

TEST(Sharadze_Georgy_ComplexNumberTest, Can_Do_Multiplication_Correctly) {
    // Arrange
    const double _re1 = 1.0;
    const double _im1 = -1.0;
    const double _re2 = 2.0;
    const double _im2 = -2.0;
    const ComplexNumber z1(_re1, _im1);
    const ComplexNumber z2(_re2, _im2);

    // Act
    ComplexNumber actual = z1 * z2;

    // Assert
    ComplexNumber expected(_re1 * _re2 - _im1 * _im2,
        _re1 * _im2 + _re2 * _im1);
    EXPECT_TRUE(actual == expected);
}

TEST(Sharadze_Georgy_ComplexNumberTest, Can_Do_Division_Correctly) {
    // Arrange
    const double _re1 = 5.0;
    const double _im1 = 5.1;
    const double _re2 = 5.0;
    const double _im2 = 4.9;
    const ComplexNumber z1(_re1, _im1);
    const ComplexNumber z2(_re2, _im2);

    // Act
    ComplexNumber actual = z1 / z2;

    // Assert
    ComplexNumber expected;
    expected.setRe((_re1 * _re2 + _im1 * _im2) / (_re2 * _re2 + _im2 * _im2));
    expected.setIm((_re2 * _im1 - _re1 * _im2) / (_re2 * _re2 + _im2 * _im2));
    EXPECT_TRUE(actual == expected);
}

TEST(Sharadze_Georgy_ComplexNumberTest, Cant_Divide_By_Zero) {
    // Arrange
    const double _re1 = 5.0;
    const double _im1 = 5.1;

    // Act
    const ComplexNumber z1(_re1, _im1);
    const ComplexNumber z2;

    // Assert
    ASSERT_ANY_THROW(z1 / z2);
}

TEST(Sharadze_Georgy_ComplexNumberTest, Can_Do_Three_Assignments_In_A_Row) {
    // Arrange
    const double _re1 = 1.0;
    const double _re2 = 2.0;
    const double _im1 = -1.0;
    const double _im2 = -2.0;
    ComplexNumber z1(_re1, _im1);
    ComplexNumber z2(_re2, _im2);

    // Act
    ComplexNumber z;
    z = z1 = z2;

    // Assert
    EXPECT_TRUE(z == z1 && z == z2);
}

TEST(Sharadze_Georgy_ComplexNumberTest, Can_Compare_Equal) {
    // Arrange
    const double _re = 1.0;
    const double _im = 2.0;
    const ComplexNumber z1(_re, _im);
    const ComplexNumber z2(z1);

    // Act
    bool result = (z1 == z2);

    // Assert
    EXPECT_TRUE(result);
}

TEST(Sharadze_Georgy_ComplexNumberTest, Can_Compare_Not_Equal) {
    // Arrange
    const double _re1 = 1.0;
    const double _re2 = 2.0;
    const double _im1 = -1.0;
    const double _im2 = -2.0;
    const ComplexNumber z1(_re1, _im1);
    const ComplexNumber z2(_re2, _im2);

    // Act
    bool result = (z1 != z2);

    // Assert
    EXPECT_TRUE(result);
}

TEST(Sharadze_Georgy_ComplexNumberTest, Can_Calc_With_Sum) {
    // Arrange
    const double _re1 = 1.0;
    const double _re2 = 2.0;
    const double _im1 = -1.0;
    const double _im2 = -2.0;
    const ComplexNumber z1(_re1, _im1);
    const ComplexNumber z2(_re2, _im2);

    // Act
    ComplexNumber result = calc(z1, z2, '+');

    // Assert
    ComplexNumber expected(_re1 + _re2, _im1 + _im2);
    EXPECT_TRUE(result == expected);
}

TEST(Sharadze_Georgy_ComplexNumberTest, Can_Calc_With_Subtraction) {
    // Arrange
    const double _re1 = 1.0;
    const double _re2 = 2.0;
    const double _im1 = -1.0;
    const double _im2 = -2.0;
    const ComplexNumber z1(_re1, _im1);
    const ComplexNumber z2(_re2, _im2);

    // Act
    ComplexNumber result = calc(z1, z2, '-');

    // Assert
    ComplexNumber expected(_re1 - _re2, _im1 - _im2);
    EXPECT_TRUE(result == expected);
}

TEST(Sharadze_Georgy_ComplexNumberTest, Can_Calc_With_Multiplication) {
    // Arrange
    const double _re1 = 1.0;
    const double _re2 = 2.0;
    const double _im1 = -1.0;
    const double _im2 = -2.0;
    const ComplexNumber z1(_re1, _im1);
    const ComplexNumber z2(_re2, _im2);

    // Act
    ComplexNumber result = calc(z1, z2, '*');

    // Assert
    ComplexNumber expected(_re1 * _re2 - _im1 * _im2,
        _re1 * _im2 + _re2 * _im1);
    EXPECT_TRUE(result == expected);
}

TEST(Sharadze_Georgy_ComplexNumberTest, Can_Calc_With_Division) {
    // Arrange
    const double _re1 = 1.0;
    const double _re2 = 2.0;
    const double _im1 = -1.0;
    const double _im2 = -2.0;
    const ComplexNumber z1(_re1, _im1);
    const ComplexNumber z2(_re2, _im2);

    // Act
    ComplexNumber result = calc(z1, z2, '/');

    // Assert
    ComplexNumber expected;
    expected.setRe((_re1 * _re2 + _im1 * _im2) / (_re2 * _re2 + _im2 * _im2));
    expected.setIm((_re2 * _im1 - _re1 * _im2) / (_re2 * _re2 + _im2 * _im2));
    EXPECT_TRUE(result == expected);
}

TEST(Sharadze_Georgy_ComplexNumberTest, Cant_Calc_With_Wrong_Operation_Format) {
    // Arrange
    const double _re1 = 1.0;
    const double _re2 = 2.0;
    const double _im1 = -1.0;
    const double _im2 = -2.0;
    const ComplexNumber z1(_re1, _im1);
    const ComplexNumber z2(_re2, _im2);

    // Assert & Act
    EXPECT_ANY_THROW(calc(z1, z2, 'n'));
}
