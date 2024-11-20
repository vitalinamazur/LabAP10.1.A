#include "pch.h"
#include "CppUnitTest.h"
#include "../LabAP10.1/LabAP10.1.cpp" // ������ ���� �� ����������

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestStudentProgram
{
    TEST_CLASS(StudentTests)
    {
    public:

        TEST_METHOD(TestPercentExcellent)
        {
            const int N = 3;
            Student students[N] = {
                { "Ivanenko", 1, IT, 5, 5, 5 },   // ³������
                { "Petrenko", 2, PHYSICS, 5, 4, 5 }, // �� �������
                { "Shevchenko", 3, MATHEMATICS, 5, 5, 5 } // ³������
            };

            double expectedPercent = 66.67; // 2 � 3 - ��������
            double actualPercent = PercentExcellent(students, N);

            Assert::AreEqual(expectedPercent, actualPercent, 0.01); // ������� 0.01
        }

        TEST_METHOD(TestGetBestStudent)
        {
            const int N = 3;
            Student students[N] = {
                { "Ivanenko", 1, IT, 3, 4, 3 },   // ������� ��� = 3.33
                { "Petrenko", 2, PHYSICS, 5, 5, 5 }, // ������� ��� = 5.00
                { "Shevchenko", 3, MATHEMATICS, 4, 4, 4 } // ������� ��� = 4.00
            };

            Student bestStudent = GetBestStudent(students, N);

            Assert::AreEqual("Petrenko", bestStudent.prizv.c_str()); // �������� �������
            Assert::AreEqual(2, bestStudent.kurs); // �������� �����
        }

        TEST_METHOD(TestAverageCalculation)
        {
            const int N = 2;
            Student students[N] = {
                { "Ivanenko", 1, IT, 5, 4, 3 }, // ������� ��� = (5+4+3)/3 = 4.0
                { "Petrenko", 2, MATHEMATICS, 3, 3, 3 } // ������� ��� = (3+3+3)/3 = 3.0
            };

            double avg1 = (students[0].fizyka + students[0].matematika + students[0].informatyka) / 3.0;
            double avg2 = (students[1].fizyka + students[1].matematika + students[1].informatyka) / 3.0;

            Assert::AreEqual(4.0, avg1, 0.01); // ������� 0.01
            Assert::AreEqual(3.0, avg2, 0.01); // ������� 0.01
        }

        TEST_METHOD(TestEmptyStudentList)
        {
            const int N = 0;
            Student* students = nullptr;

            double percent = PercentExcellent(students, N);
            Assert::AreEqual(0.0, percent); // ��������, �� ��������� 0%

            // �� ��������� GetBestStudent, ������� ����� �������.
        }
    };
}