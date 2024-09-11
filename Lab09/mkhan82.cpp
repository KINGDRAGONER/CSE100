#include <iostream>
#include <vector>
#include <map>
#include <queue>
using namespace std;

//https://stackoverflow.com/questions/32599408/comparing-nodes-in-a-linked-list-by-reference
//https://stackoverflow.com/questions/24347792/creating-struct-node-on-c
struct Node
{
    //what the tree will have
    Node *left; // pointer to the   left child
    int frequensies; //frequency of character
    char letter; // character
    Node *right; //pointer to right child

    Node(char let, int frequensies) : letter(let), frequensies(frequensies), left(0), right(0) {}
};
//in the compare we need this for the two smallest ones so we can merge em
//for our priority queue
struct CompareNodes
{
    bool operator()(Node *first_lowest_freq, Node *second_lowest_freq)
    {
        //simple checks
        if (first_lowest_freq->frequensies > second_lowest_freq->frequensies)
        {
            return true; // if greater than
        }
        else if (first_lowest_freq->frequensies < second_lowest_freq->frequensies) //if less than
        {
            return false;
        }
        else // base check which is only for the function return this is for nothing just makes the code work
        {
            return true;
        }
    }
};
//https://www.programiz.com/dsa/huffman-coding
//--------------------------------------------------------------------------------------------------------------------
void Huffmanhelper(Node *node, string code, map<char, string> &huffmanCodes)
{
    if (node==0)
    {
        return;
    }

    if (node->left == 0 && node->right == 0)
    {
        huffmanCodes[node->letter] = code;
    }
    //recursivly call
    Huffmanhelper(node->left, code + "0", huffmanCodes);
    Huffmanhelper(node->right, code + "1", huffmanCodes);
}
//https://en.cppreference.com/w/cpp/container/priority_queue
// template<
//     class T,
//     class Container = std::vector<T>,
//     class Compare = std::less<typename Container::value_type>
// > class priority_queue;
void Huffman(const vector<int> &C, const vector<char> &letters)
{
    //c = frequencies which is how often letters apears
    int n = C.size(); // n = |C|
    //Q=C
    priority_queue<Node *, vector<Node *>, CompareNodes> Q;
    //what is a priority queue
    //Every item has a priority associated with it.
    //An element with high priority is dequeued before an element with low priority.
    //If two elements have the same priority, they are served according to their order in the queue.
//adding everthing from C to Q
    for (int i = 0; i < n; i++)
    {
        Q.push(new Node(letters[i], C[i])); //C[i] tells letters[i] appears in data compressed
    }
//These nodes are the initial leaves of the Huffman tree.
//purpose is to ensure that low frequency processed first

// for i =1 to n-1 we dont need n-1
//it will run n-1    times with n being unique characters the size of vec C
//reason for n-1 is two nodes combed to 1 reducing total # of nodes by 1 and
//after n-1 iterations, all nodes will have been combined into a single tree.
    for (int i = 1; i < n; i++)
    {
        //x is the first frequency and y is the second frequency after x
        Node *x = Q.top(); //retrive the top
        Q.pop(); //remove lowest freq in q

        Node *y = Q.top(); //does the same
        Q.pop(); //remove next lowest
// allocate new node with extract-min of and add of x and y
        Node *z = new Node('\0', x->frequensies + y->frequensies);
        
        z->left = x;
        z->right = y;
//insert (Q,z)
        Q.push(z);
    }

    Node *root = Q.top();

    map<char, string> huffmanCodes;

    // Call the recursive function to generate codes
    Huffmanhelper(root, "", huffmanCodes);
//print
    for (int i = 0; i < letters.size(); ++i)
    {
        cout << letters[i] << ":" << huffmanCodes[letters[i]] << endl;
    }
}
//-----------------------------------------------------------------------------
int main()
{
    //rememeber ASCII - 8bits so 20 lettters = 160 bits as 8x20
    //remmeber freq is coubt of letters
    vector<int> frequencies; //empty vector frequencies
    vector<char> preletters = {'A', 'B', 'C', 'D', 'E', 'F'}; //precreate the symbols vector

    for(int i = 0; i < preletters.size(); ++i)
    {
        int freq;
        cin >> freq;
        frequencies.push_back(freq);
    }

    Huffman(frequencies, preletters);

    return 0;
}

//Building priotity que of n elements = O(nlogn) with insertion at logn time
//Construction of Huffsman  with n-1 internal nodes for n leaves)
//extraction of each node has a time complexity of logn aand insertion of log with total nlogn
//Generation of Huffsman is with the recursive helper function is O(n) transversal with n number of nodes
//printing probally O(n) as its just going over a vector

//overall implementation is nlogn