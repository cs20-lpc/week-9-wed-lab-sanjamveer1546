#include "ArrayQueue.hpp"
#include <iostream>
#include <string>
using namespace std;

int main()
{
    cout << "===== INT QUEUE TEST =====" << endl;
    ArrayQueue<int> q1(5);

    try
    {
        cout << q1.front() << endl;
    }
    catch (string &e)
    {
        cout << e << endl;
    }

    try
    {
        cout << q1.back() << endl;
    }
    catch (string &e)
    {
        cout << e << endl;
    }

    q1.enqueue(10);
    q1.enqueue(20);
    q1.enqueue(30);

    cout << "Front: " << q1.front() << endl;
    cout << "Back: " << q1.back() << endl;
    cout << "Length: " << q1.getLength() << endl;

    q1.dequeue();
    cout << "After one dequeue, front: " << q1.front() << endl;

    q1.enqueue(40);
    q1.enqueue(50);
    q1.enqueue(60);

    cout << "Queue is full? " << (q1.isFull() ? "Yes" : "No") << endl;

    try
    {
        q1.enqueue(70);
    }
    catch (string &e)
    {
        cout << e << endl;
    }

    cout << "Removing all elements: ";
    while (!q1.isEmpty())
    {
        cout << q1.front() << " ";
        q1.dequeue();
    }
    cout << endl;

    cout << "Queue is empty? " << (q1.isEmpty() ? "Yes" : "No") << endl;

    try
    {
        q1.dequeue();
    }
    catch (string &e)
    {
        cout << e << endl;
    }

    cout << "\n===== COPY CONSTRUCTOR TEST =====" << endl;
    ArrayQueue<int> q2(5);
    q2.enqueue(1);
    q2.enqueue(2);
    q2.enqueue(3);

    ArrayQueue<int> q3 = q2;
    cout << "q3 front: " << q3.front() << endl;
    cout << "q3 back: " << q3.back() << endl;
    cout << "q3 length: " << q3.getLength() << endl;

    cout << "\n===== ASSIGNMENT OPERATOR TEST =====" << endl;
    ArrayQueue<int> q4(5);
    q4 = q2;
    cout << "q4 front: " << q4.front() << endl;
    cout << "q4 back: " << q4.back() << endl;
    cout << "q4 length: " << q4.getLength() << endl;

    q2.clear();
    cout << "q2 empty after clear? " << (q2.isEmpty() ? "Yes" : "No") << endl;
    cout << "q4 should still have data, front: " << q4.front() << endl;

    cout << "\n===== STRING QUEUE TEST =====" << endl;
    ArrayQueue<string> qs(4);
    qs.enqueue("apple");
    qs.enqueue("banana");
    qs.enqueue("mango");

    cout << "Front: " << qs.front() << endl;
    cout << "Back: " << qs.back() << endl;

    qs.dequeue();
    cout << "After dequeue, front: " << qs.front() << endl;

    qs.enqueue("orange");
    qs.enqueue("grape");

    cout << "String queue contents: ";
    while (!qs.isEmpty())
    {
        cout << qs.front() << " ";
        qs.dequeue();
    }
    cout << endl;

    return 0;
}