
#include <iostream>
using namespace std;

class Node
{
public:
    string player;
    Node* next;

    Node(string name)
    {
        player = name;
        next = NULL;
    }
};

class Game
{
public:
    Node* head;

    Game()
    {
        head = NULL;
    }

    void addPlayer(string name)
    {
        Node* newNode = new Node(name);

        if (head == NULL)
        {
            head = newNode;
            newNode->next = head;
        }
        else
        {
            Node* current = head;

            while (current->next != head)
            {
                current = current->next;
            }

            current->next = newNode;
            newNode->next = head;
        }
    }

    void displayTurns()
    {
        Node* current = head;

        cout << "Player Turns:" << endl;

        do
        {
            cout << current->player << endl;
            current = current->next;
        }
        while (current != head);
    }

    void showNextTurn()
    {
        Node* current = head;

        for (int i = 0; i < 6; i++)
        {
            cout << current->player << endl;
            current = current->next;
        }
    }
};

int main()
{
    Game game;

    game.addPlayer("Ali");
    game.addPlayer("Ahmed");
    game.addPlayer("Hamza");
    game.addPlayer("Usman");
    game.addPlayer("Bilal");

    game.displayTurns();

    cout << "\nTurns showing return to first player:" << endl;
    game.showNextTurn();

    return 0;
}


