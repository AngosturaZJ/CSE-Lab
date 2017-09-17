
#include <iostream>
#include "Stack_char.h"
using namespace std;


int main()
{
    Stack_char s2;

    // is the stack empty
    cout << "isEmpty()\t" << s2.isEmpty() << endl;

    // push char A into Stack
    s2.push('A');
    cout << "push(A)\t";
    // print Stack
    s2.print();
    cout << endl;

    // push char Y into Stack
    s2.push('Y');
    cout << "push(Y)\t";
    // print Stack
    s2.print();
    cout << endl;

    // print the size of Stack
    cout << "size()\t" << s2.size() << "\t";
    // print Stack
    s2.print();
    cout << endl;

    // remove the last element from Stack
    cout << "pop()\t" << s2.pop() << "\t";
    // print Stack
    s2.print();
    cout << endl;

    // is Stack empty
    cout << "isEmpty()\t" << s2.isEmpty() << "\t";
    // print Stack
    s2.print();
    cout << endl;

    // push char D into Stack
    s2.push('D');
    cout << "push(D)\t";
    // print Stack
    s2.print();
    cout << endl;

    // print the last element from Stack
    cout << "top()\t" << s2.top() << "\t";
    // print Stack
    s2.print();
    cout << endl;

    // push char T into Stack
    s2.push('T');
    cout << "push(T)\t";
    // print Stack
    s2.print();
    cout << endl;

    // print and remove the last element from Stak
    cout << "pop()\t" << s2.pop() << "\t";
    // print Stack
    s2.print();
    cout << endl;

return 0;
}
