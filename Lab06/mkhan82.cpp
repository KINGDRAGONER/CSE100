#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <cmath>
#include <unordered_map>

using namespace std;
// our h function
int h(int k, int m)
{
    return k % m;
}

void Hash_Insert(vector<list<int>> &T, int k, int m)
{
    int j = h(k, m);
    T[j].push_front(k); // https://cplusplus.com/reference/list/list/push_front/
}

void Hash_Delete(vector<list<int>> &T, int k, int m)
{

    // if (it != T[j].end())
    // {
    //     T[j].erase(it);
    //     cout << k << ":DELETED;" << endl;
    // }
    // else
    // {
    //     cout << k << ":DELETE_FAILED;" << endl;
    // }
    int j = h(k, m);
    bool bval = false;
    auto beginiterator = T[j].begin();

    while (beginiterator != T[j].end())
    {
        if (*beginiterator == k)
        {
            beginiterator = T[j].erase(beginiterator);
            cout << k << ":DELETED;" << endl;
            bval = true;
            break;
        }
        else
        {
            ++beginiterator;
        }
    }

    if (!bval)
    {
        cout << k << ":DELETE_FAILED;" << endl;
    }
}
//https://www.geeksforgeeks.org/vectorbegin-vectorend-c-stl/#
void Hash_Search(vector<list<int>> &T, int k, int m)
{
    int j = h(k, m);
    list<int> &T2 = T[j];

    int idx = 0;
    bool found = false;

    for (int value : T2)
    {
        if (value == k)
        {
            found = true;
            break;
        }
        ++idx;
    }

    if (found)
    {
        cout << k << ":FOUND_AT" << j << "," << idx << ";" << endl;
    }
    else
    {
        cout << k << ":NOT_FOUND;" << endl;
    }
}

int main()
{
    int m;
    cin >> m;
    vector<list<int>> hashTable(m);

    char input;
    int key;

    while (input != 'e')
    {
        cin >> input;

        if (input == 'i')
        {
            cin >> key;
            Hash_Insert(hashTable, key, m);
        }
        else if (input == 'd')
        {
            cin >> key;
            Hash_Delete(hashTable, key, m);
        }
        else if (input == 's')
        {
            cin >> key;
            Hash_Search(hashTable, key, m);
        }
        else if (input == 'o')
        {
            for (int i = 0; i < hashTable.size(); i++)
            {
                cout << i << ":";
                for (list<int>::iterator it = hashTable[i].begin(); it != hashTable[i].end(); ++it)
                {
                    int key = *it;
                    cout << key;
                    if (next(it) != hashTable[i].end())
                    {
                        cout << "->";
                    }
                    if (next(it) == hashTable[i].end())
                    {
                        cout << "->";
                    }
                }
                cout << ";" << endl;
            }
        }
    }

    return 0;
}
// worst case o(n) best is o(1)