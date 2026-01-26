cmake_minimum_required(VERSION 3.31)
project(Math C)

set(CMAKE_C_STANDARD 11)

add_executable(Math main.c
        "Global_Funcs/spsqrt.c"
        "Number_Theory/Dvsrs.c"
        "User/NumThry.c"
        "Number_Theory/Sieve.c"
        "Number_Theory/LCM.c"
        "Number_Theory/GCF.c"
        Global_Funcs/FracSmp.c
        User/Algebra.c
        Algebra/Quadractics.c
        Algebra/SlvSys.c
        User/Geometry.c
        Geometry/PythagoreanTheorem.c
        Geometry/TriangleArea.c
        Geometry/incenter.c
        Geometry/TrapezoidArea.c
        Geometry/PolygonArea.c
        Geometry/PythagoreanInequality.c
        Geometry/PolygonAngles.c
        User/Stereometry.c
        Stereometry/RectangularPrism.c
        Stereometry/RightSquarePyramid.c
        Stereometry/LateralPyramidArea.c
        Stereometry/RightCylinder.c
        Stereometry/RightCone.c
        "User/Graphing.c"
        "User/Graphing.c"
        "Analytical_Geometry/Length.c"
        "Analytical_Geometry/Midpoint.c"
        "Analytical_Geometry/Slope.c"
        "Analytical_Geometry/SlopePointLine.c"
        "Analytical_Geometry/PointsLine.c"
        Constants.h
        "Analytical_Geometry/PointLineDistance.c"
        Misc/Misc.c
        Misc/Misc.h
        Counting/Combinations.c
        Misc/GradeCalc.c
        Misc/GradeCalc.h
        Testing/Test.c
        Testing/Test.h
        "Number_Theory/Modulo.c"
        User/Counting.c
        Counting/NthFibNum.c
        Counting/Permutations.c
        Algebra/Complex.c
        Global_Funcs/FloatMath.c
        Global_Funcs/FloatMath.h
        Algebra/func.c
        Algebra/PolynomialFctrng.c
        Global_Funcs/sscanf.c
        Global_Funcs/sscanf.h
        "Analytical_Geometry/RotatePoint.c"
        "Number_Theory/Num.h"
        Counting/Cnt.h
        Algebra/Alg.h
        Global_Funcs/Frac.h
        User/User.h
        "Analytical_Geometry/AnaGeo.h"
        Analytical_Geometry/PrintPnt.c
        Geometry/Geo.h
        Stereometry/Strometry.h
        Global_Funcs/Power.c
        Global_Funcs/Power.h
        Counting/BinomialCoefs.c
)

target_include_directories(Math PUBLIC
        ${CMAKE_SOURCE_DIR}/Global_Funcs
        ${CMAKE_SOURCE_DIR}/Algebra
        ${CMAKE_SOURCE_DIR}/Number_Theory
        ${CMAKE_SOURCE_DIR}/Counting
        ${CMAKE_SOURCE_DIR}/Analytical_Geometry
        ${CMAKE_SOURCE_DIR}/Geometry
        ${CMAKE_SOURCE_DIR}/Stereometry
        ${CMAKE_SOURCE_DIR}
)
