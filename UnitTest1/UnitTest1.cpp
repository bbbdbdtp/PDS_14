#include "pch.h"
#include "CppUnitTest.h"
#include "../PDS_14/Main.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1 {
    TEST_CLASS(UnitTest1) {
    public:
        TEST_METHOD(TestIsReflexive) {
            n = 3;

            graph[0][0] = 1;
            graph[1][1] = 1;
            graph[2][2] = 1;

            Assert::IsTrue(isReflexive());
        }
        TEST_METHOD(TestIsTransitive) {
            n = 3;

            graph[0][1] = 1;
            graph[1][2] = 1;
            graph[0][2] = 1;

            Assert::IsTrue(isTransitive());
        }
    };
}