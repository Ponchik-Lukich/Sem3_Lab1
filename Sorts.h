#pragma once

#include "Sequence.h"
#include "ArraySequence.h"
#include <ctime>

using namespace std;

#ifndef LAB1_SORTS_H
#define LAB1_SORTS_H

#endif
namespace Sorts_algorithms
{
    const string INCORRECT_INDEX = "Impossible to make this operation: Incorrect number";


    template<class T>
    Sequence<T> *SelectionSort(Sequence<T> *seq)
    {
        int size = seq->GetSize();
        if (seq->GetSize() <= 1) {
            throw out_of_range(INCORRECT_INDEX);
        }
        T temp;
        int j;

        for (int i = 0; i < size ; i++)
        {
            j = i;
            for(int k = i; k < size; k++)
            {
                if(seq->Get(j) > seq->Get(k))
                {
                    j = k;
                }
            }
            temp = seq->Get(i);
            seq->Set(i, seq->Get(j));
            seq->Set(j, temp);
        }
        return seq;
    }

    template<class T>
    void QuickSort_Support(Sequence<T> *seq, int left, int right)
    {
        int i = left;
        int j = right;
        T pivot_help = seq->Get(((left + right) / 2));
        T temp;


        while (i <= j) {
            while (seq->Get(i) < (pivot_help)) {
                i++;
            }
            while (seq->Get(j) > T (pivot_help)) {
                j--;
            }
            if (i <= j) {
                temp = seq->Get(i);
                seq->Set(i, seq->Get(j));
                seq->Set(j, temp);
                i++;
                j--;
            }

        }
        if (j > left) {
            QuickSort_Support(seq, left, j);
        }
        if (i < right) {
            QuickSort_Support(seq, i, right);
        }
    }

    template<class T>
    Sequence<T> *QuickSort(Sequence<T> *seq)
    {
        if (seq->GetSize() <= 1)
        {
            throw out_of_range(INCORRECT_INDEX);
        }
        int size = seq->GetSize();
        QuickSort_Support(seq, 0, size - 1);
        return seq;
    }

    template<class T>
    Sequence<T> *ShellSort(Sequence<T> *seq)
    {
        int size = seq->GetSize();
        int d = size / 2;
        T temp;
        while (d > 0) {
            for (int i = 0; i < size - d; i++) {
                int j = i;
                while (j >= 0 && seq->Get(j) > seq->Get(j + d)) {
                    temp = seq->Get(j);
                    seq->Set(j, seq->Get(j + d));
                    seq->Set(j + d, temp);
                    j--;
                }
            }
            d = d / 2;
        }
        return seq;
    }

}
//const string INCORRECT_INDEX = "Impossible to make this operation: Incorrect number";
//
//
//template<class T>
//Sequence<T> *SelectionSort(Sequence<T> *seq)
//{
//    int size = seq->GetSize();
//    if (seq->GetSize() <= 1) {
//        throw out_of_range(INCORRECT_INDEX);
//    }
//    T temp;
//    int j;
//
//    for (int i = 0; i < size ; i++)
//    {
//        j = i;
//        for(int k = i; k < size; k++)
//        {
//            if(seq->Get(j) > seq->Get(k))
//            {
//                j = k;
//            }
//        }
//        temp = seq->Get(i);
//        seq->Set(i, seq->Get(j));
//        seq->Set(j, temp);
//    }
//    return seq;
//}
//
//template<class T>
//void QuickSort_Support(Sequence<T> *seq, int left, int right)
//{
//    int i = left;
//    int j = right;
//    T pivot_help = seq->Get(((left + right) / 2));
//    T temp;
//
//
//    while (i <= j) {
//        while (seq->Get(i) < (pivot_help)) {
//            i++;
//        }
//        while (seq->Get(j) > T (pivot_help)) {
//            j--;
//        }
//        if (i <= j) {
//            temp = seq->Get(i);
//            seq->Set(i, seq->Get(j));
//            seq->Set(j, temp);
//            i++;
//            j--;
//        }
//
//    }
//    if (j > left) {
//        QuickSort_Support(seq, left, j);
//    }
//    if (i < right) {
//        QuickSort_Support(seq, i, right);
//    }
//}
//
//
//template<class T>
//Sequence<T> *QuickSort(Sequence<T> *seq)
//{
//    if (seq->GetSize() <= 1)
//    {
//        throw out_of_range(INCORRECT_INDEX);
//    }
//    int size = seq->GetSize();
//    QuickSort_Support(seq, 0, size - 1);
//    return seq;
//}
//
//
//template<class T>
//Sequence<T> *ShellSort(Sequence<T> *seq)
//{
//    int size = seq->GetSize();
//    int d = size / 2;
//    T temp;
//    while (d > 0) {
//        for (int i = 0; i < size - d; i++) {
//            int j = i;
//            while (j >= 0 && seq->Get(j) > seq->Get(j + d)) {
//                temp = seq->Get(j);
//                seq->Set(j, seq->Get(j + d));
//                seq->Set(j + d, temp);
//                j--;
//            }
//        }
//        d = d / 2;
//    }
//    return seq;
//}

template <class T>
bool IsCorrect(Sequence<T>* seq)
{
    int size = seq->GetSize();
    int i = 1;
    while ( i <= size - 1)
    {
        if (seq->Get(i) >= seq->Get(i - 1))
        {
            i++;
        }
        else
        {
            return false;
        }
    }
    return true;
}


template<class T>
double Time(Sequence<T> *seq, Sequence<T> *(*sort)(Sequence<T> *seq))
{
    clock_t startTime = clock();
    seq = sort(seq);
    clock_t endTime = clock();
    double time = (double) (endTime - startTime) / CLOCKS_PER_SEC;
    return time;
}

template<class T>
void Print(Sequence<T> *seq)
{
    int size = seq->GetSize();
    for (int i = 0; i < size; i++)
    {
        cout << seq->Get(i) << ' ';
    }
    cout << endl;
}