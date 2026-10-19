
#include <iostream>
using namespace std;

#define SIZE 5

class Deque
{
    int arr[SIZE];
    int front, rear, count;

public:
    Deque()
    {
        front = -1;
        rear = -1;
        count = 0;
    }

    void insertFront(int id)
    {
        if (count == SIZE)
        {
            cout << "Deque is full!" << endl;
            return;
        }

        if (count == 0)
        {
            front = 0;
            rear = 0;
        }
        else
        {
            front = (front - 1 + SIZE) % SIZE;
        }

        arr[front] = id;
        count++;

        cout << id << " added at front." << endl;
    }

    void insertRear(int id)
    {
        if (count == SIZE)
        {
            cout << "Deque is full!" << endl;
            return;
        }

        if (count == 0)
        {
            front = 0;
            rear = 0;
        }
        else
        {
            rear = (rear + 1) % SIZE;
        }

        arr[rear] = id;
        count++;

        cout << id << " added at rear." << endl;
    }

    void removeFront()
    {
        if (count == 0)
        {
            cout << "Deque is empty!" << endl;
            return;
        }

        cout << "Removed from front: "
             << arr[front] << endl;

        if (count == 1)
        {
            front = -1;
            rear = -1;
        }
        else
        {
            front = (front + 1) % SIZE;
        }

        count--;
    }

    void removeRear()
    {
        if (count == 0)
        {
            cout << "Deque is empty!" << endl;
            return;
        }

        cout << "Removed from rear: "
             << arr[rear] << endl;

        if (count == 1)
        {
            front = -1;
            rear = -1;
        }
        else
        {
            rear = (rear - 1 + SIZE) % SIZE;
        }

        count--;
    }

    void display()
    {
        if (count == 0)
        {
            cout << "Deque is empty." << endl;
            return;
        }

        cout << "Front -> ";

        int i = front;

        for (int j = 0; j < count; j++)
        {
            cout << arr[i] << " ";
            i = (i + 1) % SIZE;
        }

        cout << "<- Rear" << endl;
    }
};

int main()
{
    Deque d;

    d.insertRear(301);
    d.insertRear(302);
    d.insertFront(300);

    d.display();

    d.removeFront();
    d.display();

    d.removeRear();
    d.display();

    return 0;
}

