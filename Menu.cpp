#include "ArraySequence.h"
#include "ListSequence.h"
#include "Sorts.h"
#include "random"
#include <string>


using namespace Sorts_algorithms;

std::random_device rd;
std::mt19937 mt(rd());
std::uniform_real_distribution<float> dist(-1000.0, 1000.0);

template<class T>
Sequence<T>* CreateArraySequence(int size)
{
    auto seq = new ArraySequence<T>(size);
    for (int i = 0; i < size; i++)
    {
        T item = dist(mt);
        seq->Set(i, item);
    }
    return seq;
}

template<class T>
Sequence<T>* CreateListSequence(int size)
{
    auto seq = new ListSequence<T>(size);
    for (int i = 0; i < size; i++)
    {
        T item = dist(mt);
        seq->Set(i, item);
    }
    return seq;
}

template<class T>
Sequence<T>* EnterArraySequence(int size)
{
    auto seq = new ArraySequence<T>(size);
    cout << "Enter " << size << " numbers:" << endl;
    for (int i = 0; i < size; i++)
    {
        T item;
        cout << "Your number: ";
        cin >> item;
        cout << endl;
        seq->Set(i, item);
    }
    return seq;
}

template<class T>
Sequence<T>* EnterListSequence(int size)
{
    auto seq = new ListSequence<T>(size);
    cout << "Enter " << size << " numbers:" << endl;
    for (int i = 0; i < size; i++)
    {
        T item;
        cout << "Your number: ";
        cin >> item;
        cout << endl;
        seq->Set(i, item);
    }
    return seq;
}

template<class T>
Sequence<T>* DuplicateArraySequence(Sequence<T>* seq)
{
    int size = seq->GetSize();
    auto seq1 = new ArraySequence<T>(size);
    for (int i = 0; i < size; i++)
    {
        T item = seq->Get(i);
        seq1->Set(i, item);
    }
    return seq1;
}

template<class T>
Sequence<T>* DuplicateListSequence(Sequence<T>* seq)
{
    int size = seq->GetSize();
    auto seq1 = new ListSequence<T>(size);
    for (int i = 0; i < size; i++)
    {
        T item = seq->Get(i);
        seq1->Set(i, item);
    }
    return seq1;
}


void ChooseRealization()
{
    cout << ("Choose the sequence implementation:") << endl;
    cout << ("1 <- ListSequence") << endl;
    cout << ("2 <- ArraySequence") << endl;
}

void ChooseSAlg()
{
    cout << ("Choose the type of sorting algorithm:") << endl;
    cout << ("1 <- Selection Sort") << endl;
    cout << ("2 <- Quick Sort") << endl;
    cout << ("3 <- Shell Sort") << endl;
}

string TimeConv(double time)
{
    string Tstring;
    if (time < 1.0)
    {
        Tstring = to_string(time*1000) + " ms";
    }
    else
    {
        Tstring = to_string(time) + " s";
    }
    return Tstring;
}

template<class T>
void Final(Sequence<T>* seq)
{
    cout << "Sorted sequence: ";
    Print(seq);
    cout << endl;
    if (IsCorrect(seq) == true)
    {
        cout << "Sorted sequence is Correct!" << endl;
    }
    else
    {
        cout << "Sorted sequence is Incorrect! There is a mistake!" << endl;
    }
}

template<class T>
void Run(Sequence<T>* seq)
{
    cout << "Your sequence: ";
    Print(seq);
    cout << endl;
    ChooseSAlg();
    int choice = 0;
    cin >> choice;
    while (choice < 1 || choice > 3)
    {
        cout << ("Wrong number, try again!") << endl;
        cin >> choice;
    }
    cout << "Your sequence: ";
    Print(seq);
    Sequence<int>* seq2;
    if (choice == 1)
    {
        seq2 = SelectionSort(seq);
        Final(seq2);
    }

    if (choice == 2)
    {
        seq2 = QuickSort(seq);
        Print(seq);
        Final(seq2);
    }

    if (choice == 3)
    {
        seq2 = ShellSort(seq);
        Final(seq2);
    }

    delete(seq);
}

string Return_algorithm(int choice)
{
    string algorithm;
    switch (choice)
    {
        case 1:
            algorithm = "Selection sort";
            break;
        case 2:
            algorithm = "Quick sort";
            break;
        case 3:
            algorithm = "Shell sort";
            break;
    }
    return algorithm;
}

template<class T>
double RunCompare_help(int choice, Sequence<T>* seq)
{
    double time;
    string algorithm;
    switch (choice)
    {
        case 1:
            time = Time(seq, SelectionSort);
            break;
        case 2:
            time = Time(seq, QuickSort);
            break;
        case 3:
            time = Time(seq, ShellSort);
            break;
    }
    return time;
}


template<class T>
void RunCompare(Sequence<T>* seq, Sequence<T>* seq1)
{

    string Tstring;

    string Tstring1;

    ChooseSAlg();

    int choice = 0;

    cin >> choice;

    int choice1 = 0;

    cin >> choice1;

    while (choice < 1 || choice > 3 || choice1 < 1 || choice1 > 3)
    {
        cout << ("Wrong numbers, try again!") << endl;
        cin >> choice;
        cin >> choice1;
    }

    double time = RunCompare_help(choice, seq);

    double time1 = RunCompare_help(choice1, seq1);

    Tstring = TimeConv(time);

    Tstring1 = TimeConv(time1);

    string algorithm = Return_algorithm(choice);

    string algorithm1 = Return_algorithm(choice1);

    cout << "Time spent on " << algorithm << ": " << Tstring << endl;

    cout << "Time spent on " << algorithm1 << ": " << Tstring1 << endl;

    if (time < time1)
    {
        cout << algorithm << " is more efficient" << endl;
    }
    else
    {
        cout << algorithm1 << " is more efficient" << endl;
    }

    delete(seq);

    delete(seq1);

}

void AutomaticCheck(int compare)
{
    int size, choice;
    Sequence<int>* seq;
    ChooseRealization();
    cin >> choice;
    while (choice != 1 && choice != 2)
    {
        cout << ("Wrong number, try again!") << endl;
        cin >> choice;
    }
    cout << ("Enter size of sequence: ");
    cin >> size;
    cout << endl;
    if (choice == 1)
    {
        seq = CreateListSequence<int>(size);
        if (compare == 0)
        {
            Run(seq);
        }
        else
        {
            Sequence<int>* seq1;
            seq1 = DuplicateListSequence<int>(seq);
            RunCompare(seq, seq1);
        }
    }
    if (choice == 2)
    {
        seq = CreateArraySequence<int>(size);
        if (compare == 0)
        {
            Run(seq);
        }
        else
        {
            Sequence<int>* seq1;
            seq1 = DuplicateArraySequence<int>(seq);
            RunCompare(seq, seq1);
        }
    }

}

void ManualCheck()
{
    int size, choice;
    Sequence<int>* seq;
    ChooseRealization();
    cin >> choice;
    while (choice != 1 && choice != 2)
    {
        cout << ("Wrong number, try again!") << endl;
        cin >> choice;
    }
    cout << ("Enter size of sequence: ");
    cin >> size;
    cout << endl;

    if (choice == 1)
    {
        seq = EnterListSequence<int>(size);
        Run(seq);
    }
    if (choice == 2)
    {
        seq = EnterArraySequence<int>(size);
        Run(seq);
    }
}

int main() {
    while (true)
    {
        cout << ("----------------------------------------------\n");
        cout << ("1 <- Automatic sort check") << endl;
        cout << ("2 <- Manual sort check") << endl;
        cout << ("3 <- Compare sorting algorithms") << endl;
        cout << ("0 <- Exit") << endl;
        cout << ("----------------------------------------------\n");

        int action = 0;
        cin >> action;

        if (action == 0)
        {
            cout << ("Exit!\n");
            break;
        }
        else if (4 < action )
        {
            cout << ("Incorrect command") << endl;
        }
        else if (action == 1)
        {
            AutomaticCheck(0);
        }
        else if (action == 2)
        {
            ManualCheck();
        }
        else if (action == 3)
        {
            AutomaticCheck(1);
        }

    }
    return 0;
}
