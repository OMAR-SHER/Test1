#include<iostream>
using namespace std;
struct Node
{
    int data;
    struct Node* next;
};
void SortedInsert(struct Node** H, int x)
{
    struct Node* t, * q = NULL, * p = *H;

    t = new Node;
    t->data = x;
    t->next = NULL;

    if (*H == NULL)
        *H = t;
    else
    {
        while (p && p->data < x)
        {
            q = p;
            p = p->next;
        }
        if (p == *H)
        {
            t->next = *H;
            *H = t;
        }
        else
        {
            t->next = q->next;
            q->next = t;
        }
    }

}
void  Search(struct Node* p, int key)
{
    bool valid = true;
    while (p != NULL)
    {
        if (key == p->data)
        {
            valid = false;
            cout << "data found : " << p->data << endl;
            //return p;
        }
        p = p->next;
    }
    //return NULL;
    if (valid == true)
    {
        cout << "data not found\n";
    }

}
int hash1(int key)
{
    return key % 10;
}
void Insert(struct Node* H[], int key)
{
    int index = hash1(key);
    SortedInsert(&H[index], key);
}
int main()
{
    struct Node* HT[10];
    struct Node* temp;
    int i;

    for (i = 0; i < 10; i++)
        HT[i] = NULL;

    Insert(HT, 12);
    Insert(HT, 22);
    Insert(HT, 22);
    Insert(HT, 42);
    Insert(HT, 17);

    //temp =
     Search(HT[hash1(22)], 22);
     Search(HT[hash1(22)], 17);
     Search(HT[hash1(7)], 17);
   // cout << temp->data;

    return 0;
}