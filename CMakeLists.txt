cmake_minimum_required(VERSION 3.31)
project(Math C)

set(CMAKE_C_STANDARD 11)

add_executable(Math main.c
        "Number Theory/UGCF.c"
        "Global_Funcs/spsqrt.c"
        "Number Theory/Dvsrs.c"
        "Number Theory/NumThry.c"
        "Number Theory/Primes.c"
        "Global_Funcs/Sieve.c"
        Global_Funcs/power.c
        Global_Funcs/power.h
        "Number Theory/Fctrs.c"
        "Number Theory/Fctrs.h"
        "Number Theory/LCM.c"
        "Number Theory/LCM.h"
        Global_Funcs/GCF.c
        Global_Funcs/GCF.h
        Algebra/FracSmp.c
        Algebra/FracSmp.h
        Algebra/Algebra.c
        Algebra/Algebra.h
        Algebra/SmpSqrt.c
        Algebra/SmpSqrt.h
        Algebra/Quadractics.c
        Algebra/Quadractics.h
        Algebra/SlvSys.c
        Algebra/SlvSys.h
        Geometry/Geometry.c
        Geometry/Geometry.h
        Geometry/PythagoreanTheorem.c
        Geometry/PythagoreanTheorem.h
        Geometry/TriangleArea.c
        Geometry/TriangleArea.h
        Geometry/incenter.c
        Geometry/incenter.h
        Geometry/TrapezoidArea.c
        Geometry/TrapezoidArea.h
        Geometry/PolygonArea.c
        Geometry/PolygonArea.h
        Geometry/PythagoreanInequality.c
        Geometry/PythagoreanInequality.h
        Geometry/PolygonAngles.c
        Geometry/PolygonAngles.h
        Stereometry/Stereometry.c
        Stereometry/Stereometry.h
        Stereometry/RectangularPrism.c
        Stereometry/RectangularPrism.h
        Stereometry/RightSquarePyramid.c
        Stereometry/RightSquarePyramid.h
        Stereometry/LateralPyramidArea.c
        Stereometry/LateralPyramidArea.h
        Stereometry/RightCylinder.c
        Stereometry/RightCylinder.h
        Stereometry/RightCone.c
        Stereometry/RightCone.h
        "Analytical Geometry/Graphing.c"
        "Analytical Geometry/Graphing.h"
        "Analytical Geometry/Graphing.c"
        "Analytical Geometry/Length.c"
        "Analytical Geometry/Length.h"
        "Analytical Geometry/Midpoint.c"
        "Analytical Geometry/Midpoint.h"
        "Analytical Geometry/Slope.c"
        "Analytical Geometry/Slope.h"
        "Analytical Geometry/SlopePointLine.c"
        "Analytical Geometry/SlopePointLine.h"
        "Analytical Geometry/PointsLine.c"
        "Analytical Geometry/PointsLine.h"
        Constants.h
        "Analytical Geometry/PointLineDistance.c"
        "Analytical Geometry/PointLineDistance.h"
        Misc/Misc.c
        Misc/Misc.h
        Counting/Combinations.c
        Counting/Combinations.h
        Global_Funcs/Factorial.c
        Global_Funcs/Factorial.h
        Misc/GradeCalc.c
        Misc/GradeCalc.h
        Testing/Test.c
        Testing/Test.h
        "Number Theory/Modulo.c"
        "Number Theory/Modulo.h"
        Counting/Counting.c
        Counting/Counting.h
        Counting/NthFibNum.c
        Counting/NthFibNum.h
        Algebra/ImaginaryMath.c
        Algebra/ImaginaryMath.h
        Global_Funcs/FloatMath.c
        Global_Funcs/FloatMath.h
        Global_Funcs/func.c
        Global_Funcs/func.h
        Algebra/FunctionCalc.c
        Algebra/FunctionCalc.h
        Algebra/PolynomialFctrng.c
        Algebra/PolynomialFctrng.h
        Algebra/USynthDiv.c
        Algebra/USynthDiv.h
)

target_include_directories(Math PUBLIC
        ${CMAKE_SOURCE_DIR}/Global_Funcs
        ${CMAKE_SOURCE_DIR}
)
