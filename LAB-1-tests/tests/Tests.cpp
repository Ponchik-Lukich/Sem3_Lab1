#include "gtest/gtest.h"
#include "../../ListSequence.h"
#include "../../Sorts.h"
#include "../../Menu.h"
#include "../../Complex.h"
#include "../../Function.h"

using namespace Sorts_algorithms;

int arr[] = {1, 2, 3, 4, 5};
float arr2[] = {1.1, 2.2, 3.3, 4.4, 5.5};
int arr3[] = {4, 323, -999, 8, 5};
double arr4[] = {1.112, 5.3, 1.111, 2.5, 7.9, 525.0, -76.5};
complex arr5[] = {complex(3,3), complex(1,1), complex(2,2), complex(1, 2)};

int *array_1 = arr;
float *array_2 = arr2;
int *array_3 = arr3;
double  *array_4 = arr4;
complex *array_5 = arr5;

TEST(DynamicArray, Default)
{
    DynamicArray<int> array = DynamicArray<int>(0);
    ASSERT_EQ(0, array.GetSize());
}

TEST(DynamicArray, Getsize)
{
    DynamicArray<int> array = DynamicArray<int>(10);
    ASSERT_EQ(10, array.GetSize());
}

TEST(DynamicArray, Float)
{
    DynamicArray<float> array = DynamicArray<float>(array_2,5);
    ASSERT_EQ(5, array.GetSize());
    EXPECT_FLOAT_EQ(1.1, array.Get(0));
    EXPECT_FLOAT_EQ(5.5, array.Get(4));
}

TEST(DynamicArray, FromArray_Get)
{
    DynamicArray<int> array = DynamicArray<int>(array_1, 5);
    ASSERT_EQ(5, array.GetSize());
    ASSERT_EQ(1, array.Get(0));
    ASSERT_EQ(5, array.Get(4));
}

TEST(DynamicArray, Set)
{
    DynamicArray<int> array = DynamicArray<int>(3);
    array.Set(2,999);
    ASSERT_EQ(999, array.Get(2));
}

TEST(DynamicArray, Resize)
{
    DynamicArray<int> array = DynamicArray<int>(array_1, 5);
    array.Resize(3);
    ASSERT_EQ(3, array.Get(2));
}

TEST(LinkedList, InitDefault)
{
    LinkedList<int> arr = LinkedList<int>();
    ASSERT_EQ(0, arr.GetLength());
}

TEST(LinkedList, Creation_from_array)
{
    LinkedList<int> list = LinkedList<int>(array_1, 5);
    ASSERT_EQ(5,list.GetLength());
}

TEST(LinkedList, Get)
{
    LinkedList<int> list = LinkedList<int>(array_1, 5);
    ASSERT_EQ(1,list.Get(0));
    ASSERT_EQ(5,list.Get(4));
}

TEST(LinkedList, float)
{
    LinkedList<float> list = LinkedList<float>(array_2, 5);
    EXPECT_FLOAT_EQ(1.1,list.Get(0));
    EXPECT_FLOAT_EQ(5.5,list.Get(4));
}

TEST(LinkedList, GetLast_GetFirst)
{
    LinkedList<int> list = LinkedList<int>(array_1, 5);
    ASSERT_EQ(1,list.GetFirst());
    ASSERT_EQ(5,list.GetLast());
}

TEST(LinkedList, Getsublist)
{
    LinkedList<int> list = LinkedList<int>(array_1, 5);
    LinkedList<int>* list1 = new LinkedList<int>();
    list1 = list.GetSublist(1,3);
    ASSERT_EQ(2,list1->GetFirst());
    ASSERT_EQ(4,list1->GetLast());
}

TEST(LinkedList, Append)
{
    LinkedList<int> list = LinkedList<int>(array_1, 5);
    list.Append(22);
    ASSERT_EQ(22, list.Get(5));
}

TEST(LinkedList, Prepend)
{
    LinkedList<int> list = LinkedList<int>(array_1, 5);
    list.Prepend(22);
    ASSERT_EQ(22, list.Get(0));
}

TEST(LinkedList, Insert)
{
    LinkedList<int> list = LinkedList<int>(array_1, 5);
    list.InsertAt(11,2);
    ASSERT_EQ(11, list.Get(2));
}

TEST(LinkedList, Clear)
{
    LinkedList<int> list = LinkedList<int>(array_1, 5);
    list.Clear();
    ASSERT_EQ(0, list.GetLength());
}

TEST(ArraySequence, Get_First_Last)
{
    DynamicArray<int> array = DynamicArray<int>(array_1, 5);
    ArraySequence<int> seq = ArraySequence<int>(&array);
    ASSERT_EQ(1, seq.GetFirst());
    ASSERT_EQ(5, seq.GetLast());
}

TEST(ArraySequence, GetSubseq)
{
    DynamicArray<int> array = DynamicArray<int>(array_1, 5);
    ArraySequence<int> seq = ArraySequence<int>(&array);
    ArraySequence<int> *seq1 = new ArraySequence<int>();
    seq1 = seq.GetSubSequence(0, 1);
    ASSERT_EQ(1, seq1->GetFirst());
    ASSERT_EQ(2, seq1->GetLast());
}

TEST(ArraySequence, Set1)
{
    DynamicArray<int> array = DynamicArray<int>(array_1, 5);
    ArraySequence<int> seq = ArraySequence<int>(&array);
    seq.Set(0,11);
    ASSERT_EQ(11, seq.Get(0));
}

TEST(ListSequence, Get_First_Get_Last)
{
    LinkedList<int> list = LinkedList<int>(array_1, 5);
    ListSequence<int> seq = ListSequence<int>(&list);
    ASSERT_EQ(1, seq.GetFirst());
    ASSERT_EQ(5, seq.GetLast());
}

TEST(ListSequence, GetSize)
{
    LinkedList<int> list = LinkedList<int>(array_1, 5);
    ListSequence<int> seq = ListSequence<int>(&list);
    ASSERT_EQ(5, seq.GetSize());
}

TEST(ListSequence, Set)
{
    LinkedList<int> list = LinkedList<int>(array_1, 5);
    ListSequence<int> seq = ListSequence<int>(&list);
    seq.Set(1, 11);
    ASSERT_EQ(11, seq.Get(1));
}

TEST(Sorts, ArraySelectionSort)
{
    Sequence<int>* seq;
    auto seq_help = new ArraySequence<int>(array_3, 5);
    seq = seq_help;
    seq = SelectionSort(seq, compareT);
    ASSERT_EQ(-999, seq->Get(0));
    ASSERT_EQ(4, seq->Get(1));
    ASSERT_EQ(5, seq->Get(2));
    ASSERT_EQ(8, seq->Get(3));
    ASSERT_EQ(323, seq->Get(4));

}

TEST(Sorts, ArraytQuickSort)
{
    Sequence<int>* seq;
    auto seq_help = new ArraySequence<int>(array_3, 5);
    seq = seq_help;
    seq = QuickSort(seq, compareT);
    ASSERT_EQ(-999, seq->Get(0));
    ASSERT_EQ(4, seq->Get(1));
    ASSERT_EQ(5, seq->Get(2));
    ASSERT_EQ(8, seq->Get(3));
    ASSERT_EQ(323, seq->Get(4));

}

TEST(Sorts, ArrayShellSort)
{
    Sequence<int>* seq;
    auto seq_help = new ArraySequence<int>(array_3, 5);
    seq = seq_help;
    seq = ShellSort(seq, compareT);
    ASSERT_EQ(-999, seq->Get(0));
    ASSERT_EQ(4, seq->Get(1));
    ASSERT_EQ(5, seq->Get(2));
    ASSERT_EQ(8, seq->Get(3));
    ASSERT_EQ(323, seq->Get(4));

}

TEST(Sorts, DoubleArraySelectionSort)
{
    Sequence<double>* seq;
    auto seq_help = new ArraySequence<double>(array_4, 7);
    seq = seq_help;
    seq = SelectionSort(seq, compareT);
    EXPECT_FLOAT_EQ(-76.5, seq->Get(0));
    EXPECT_FLOAT_EQ(1.111, seq->Get(1));
    EXPECT_FLOAT_EQ(1.112, seq->Get(2));
    EXPECT_FLOAT_EQ(2.5, seq->Get(3));
    EXPECT_FLOAT_EQ(5.3, seq->Get(4));
    EXPECT_FLOAT_EQ(7.9, seq->Get(5));
    EXPECT_FLOAT_EQ(525.0, seq->Get(6));
}

TEST(Sorts, DoubleArrayQuickSort)
{
    Sequence<double>* seq;
    auto seq_help = new ArraySequence<double>(array_4, 7);
    seq = seq_help;
    seq = QuickSort(seq, compareT);
    EXPECT_FLOAT_EQ(-76.5, seq->Get(0));
    EXPECT_FLOAT_EQ(1.111, seq->Get(1));
    EXPECT_FLOAT_EQ(1.112, seq->Get(2));
    EXPECT_FLOAT_EQ(2.5, seq->Get(3));
    EXPECT_FLOAT_EQ(5.3, seq->Get(4));
    EXPECT_FLOAT_EQ(7.9, seq->Get(5));
    EXPECT_FLOAT_EQ(525.0, seq->Get(6));

}

TEST(Sorts, DoubleArrayShellSort)
{
    Sequence<double>* seq;
    auto seq_help = new ArraySequence<double>(array_4, 7);
    seq = seq_help;
    seq = ShellSort(seq, compareT);
    EXPECT_FLOAT_EQ(-76.5, seq->Get(0));
    EXPECT_FLOAT_EQ(1.111, seq->Get(1));
    EXPECT_FLOAT_EQ(1.112, seq->Get(2));
    EXPECT_FLOAT_EQ(2.5, seq->Get(3));
    EXPECT_FLOAT_EQ(5.3, seq->Get(4));
    EXPECT_FLOAT_EQ(7.9, seq->Get(5));
    EXPECT_FLOAT_EQ(525.0, seq->Get(6));

}

TEST(Sorts, ListSelectionSort)
{
    Sequence<int>* seq;
    auto seq_help = new ListSequence<int>(array_3, 5);
    seq = seq_help;
    seq = SelectionSort(seq, compareT);
    ASSERT_EQ(-999, seq->Get(0));
    ASSERT_EQ(4, seq->Get(1));
    ASSERT_EQ(5, seq->Get(2));
    ASSERT_EQ(8, seq->Get(3));
    ASSERT_EQ(323, seq->Get(4));

}

TEST(Sorts, ListtQuickSort)
{
    Sequence<int>* seq;
    auto seq_help = new ListSequence<int>(array_3, 5);
    seq = seq_help;
    seq = QuickSort(seq, compareT);
    ASSERT_EQ(-999, seq->Get(0));
    ASSERT_EQ(4, seq->Get(1));
    ASSERT_EQ(5, seq->Get(2));
    ASSERT_EQ(8, seq->Get(3));
    ASSERT_EQ(323, seq->Get(4));

}

TEST(Sorts, ListShellSort)
{
    Sequence<int>* seq;
    auto seq_help = new ListSequence<int>(array_3, 5);
    seq = seq_help;
    seq = ShellSort(seq, compareT);
    ASSERT_EQ(-999, seq->Get(0));
    ASSERT_EQ(4, seq->Get(1));
    ASSERT_EQ(5, seq->Get(2));
    ASSERT_EQ(8, seq->Get(3));
    ASSERT_EQ(323, seq->Get(4));

}

TEST(Sorts, DoubleListSelectionSort)
{
    Sequence<double>* seq;
    auto seq_help = new ListSequence<double>(array_4, 7);
    seq = seq_help;
    seq = SelectionSort(seq, compareT);
    EXPECT_FLOAT_EQ(-76.5, seq->Get(0));
    EXPECT_FLOAT_EQ(1.111, seq->Get(1));
    EXPECT_FLOAT_EQ(1.112, seq->Get(2));
    EXPECT_FLOAT_EQ(2.5, seq->Get(3));
    EXPECT_FLOAT_EQ(5.3, seq->Get(4));
    EXPECT_FLOAT_EQ(7.9, seq->Get(5));
    EXPECT_FLOAT_EQ(525.0, seq->Get(6));

}

TEST(Sorts, DoubleListQuickSort)
{
    Sequence<double>* seq;
    auto seq_help = new ListSequence<double>(array_4, 7);
    seq = seq_help;
    seq = QuickSort(seq, compareT);
    EXPECT_FLOAT_EQ(-76.5, seq->Get(0));
    EXPECT_FLOAT_EQ(1.111, seq->Get(1));
    EXPECT_FLOAT_EQ(1.112, seq->Get(2));
    EXPECT_FLOAT_EQ(2.5, seq->Get(3));
    EXPECT_FLOAT_EQ(5.3, seq->Get(4));
    EXPECT_FLOAT_EQ(7.9, seq->Get(5));
    EXPECT_FLOAT_EQ(525.0, seq->Get(6));

}

TEST(Sorts, DoubleListShellSort)
{
    Sequence<double>* seq;
    auto seq_help = new ListSequence<double>(array_4, 7);
    seq = seq_help;
    seq = ShellSort(seq, compareT);
    EXPECT_FLOAT_EQ(-76.5, seq->Get(0));
    EXPECT_FLOAT_EQ(1.111, seq->Get(1));
    EXPECT_FLOAT_EQ(1.112, seq->Get(2));
    EXPECT_FLOAT_EQ(2.5, seq->Get(3));
    EXPECT_FLOAT_EQ(5.3, seq->Get(4));
    EXPECT_FLOAT_EQ(7.9, seq->Get(5));
    EXPECT_FLOAT_EQ(525.0, seq->Get(6));

}

TEST(Sorts, ComplexSelectionSort)
{
    Sequence<complex>* seq;
    auto seq_help = new ArraySequence<complex>(array_5, 4);
    seq = seq_help;
    seq = SelectionSort(seq, compareT);
    ASSERT_EQ(complex(1,1), seq->Get(0));
    ASSERT_EQ(complex(1,2), seq->Get(1));
    ASSERT_EQ(complex(2,2), seq->Get(2));
    ASSERT_EQ(complex(3,3), seq->Get(3));

}

TEST(Sorts, ComplexQuickSort)
{
    Sequence<complex>* seq;
    auto seq_help = new ArraySequence<complex>(array_5, 4);
    seq = seq_help;
    seq = QuickSort(seq, compareT);
    ASSERT_EQ(complex(1,1), seq->Get(0));
    ASSERT_EQ(complex(1,2), seq->Get(1));
    ASSERT_EQ(complex(2,2), seq->Get(2));
    ASSERT_EQ(complex(3,3), seq->Get(3));

}

TEST(Sorts, ComplexShellSort)
{
    Sequence<complex>* seq;
    auto seq_help = new ArraySequence<complex>(array_5, 4);
    seq = seq_help;
    seq = ShellSort(seq, compareT);
    ASSERT_EQ(complex(1,1), seq->Get(0));
    ASSERT_EQ(complex(1,2), seq->Get(1));
    ASSERT_EQ(complex(2,2), seq->Get(2));
    ASSERT_EQ(complex(3,3), seq->Get(3));

}
/*
EXPECT_FLOAT_EQ(0,0);
EXPECT_ANY_THROW(arr.GetFirst());
EXPECT_ANY_THROW(arr.GetLast());
*/
