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

    void addNode()
    {
        int nim;
        cout << "\nMasukan Nomor Mahasiswa : ";
        cin >> nim;

        Node *nodeBaru = new Node;
        nodeBaru->noMhs = nim;

        if (START == NULL || nim <= START->noMhs)
        {
            if ((START != NULL) && (nim == START->noMhs))
            {
                cout << "\nDuplikasi noMhs tidak diijinkan\n";
                return;
            }
        }

        Node *previous = START;
        Node *current = START;

        while ((current != NULL) && (nim >= current->noMhs))
        {
            if (nim == current->noMhs)
            {
                cout << "\nDuplikasi tidak diijinkan\n";
                return;
            }
            previous = current;
            current = current->next;
        }
        nodeBaru->next = current;
        previous->next = nodeBaru;
    }

    bool listEmpty()
    {
        return (START == NULL);
    }

    bool Search(int nim, Node **previous, Node **current)
    {
        *previous = *current;
        *current = (*current)->next;

        while ((*current != NULL) && (nim != (*current)->noMhs))
        {
            *previous = *current;
            *current = (*current)->next;
        }

        return (*current != NULL);
    }

    bool delNode(int nim)
    {
        Node *current, *previous;
        if (!Search(nim, &previous,  &current))
            return false;

        if (current == START) 
            START = START->next;
        else
            previous->next = current->next;

        delete current;
        return true;
    }
    
    void traverse()
    {
        if (listEmpty())
        {
            cout << "\nList Kosong\n";
        }
        else
        {
            cout << "\nData didalam list adalah :\n";
            currentNode = currentNode->next;
        }
        cout << endl
    }
}

int main ()
{
    List mhs;
    int nim;
    char ch;
    while(1)
    {
        cout
            <<"Menu" << endl;
            cout << endl
                << "1. Menambah data kedalam list" << endl;
            cout << "2. Menghapus data dari halaman list" <<endl;
            cout << "Menampilkan data dalam list" << endl;
            cout << "4. Mencari data dalam list" << endl;
            cout << " 5. Keluar " << endl;
            cout
                << "Masukan pilihan (1-5): " << endl;
                cin >> ch;
    }
