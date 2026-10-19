
#include <iostream>
using namespace std;

#define SIZE 5

class Queue
{
    int arr[SIZE];
    int front, rear;

public:
    Queue()
    {
        front = -1;
        rear = -1;
    }

    void enqueue(int token)
    {
        if (rear == SIZE - 1)
        {
            cout << "Queue Overflow!" << endl;
            return;
        }

        if (front == -1)
        {
            front = 0;
        }

        rear++;
        arr[rear] = token;

        cout << "Customer " << token << " added." << endl;
    }

    void dequeue()
    {
        if (front == -1 || front > rear)
        {
            cout << "Queue Underflow! No customer waiting." << endl;
            return;
        }

        cout << "Serving customer: " << arr[front] << endl;
        front++;

        if (front > rear)
        {
            front = -1;
            rear = -1;
        }
    }

    void display()
    {
        if (front == -1)
        {
            cout << "No customers waiting." << endl;
            return;
        }

        cout << "Waiting customers: ";

        for (int i = front; i <= rear; i++)
        {
            cout << arr[i] << " ";
        }

        cout << endl;
    }

    void countCustomers()
    {
        if (front == -1)
        {
            cout << "Waiting customers: 0" << endl;
        }
        else
        {
            cout << "Waiting customers: "
                 << rear - front + 1 << endl;
        }
    }
};

int main()
{
    Queue q;

    q.enqueue(101);
    q.enqueue(102);
    q.enqueue(103);

    q.display();
    q.countCustomers();

    q.dequeue();

    q.display();
    q.countCustomers();

    return 0;
}

