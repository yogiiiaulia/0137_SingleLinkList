#include <iostream>
using namespace std;

class Node
{
    public : 
        int noMhs;
        Node *next;
};

class List
{
    Node *START;

public:
    List()
    {
        START = NULL;
    }

   