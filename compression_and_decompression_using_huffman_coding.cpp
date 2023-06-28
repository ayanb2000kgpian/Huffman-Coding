#include<iostream>
#include<bits/stdc++.h>
#define int long long
using namespace std;

//creating the Node for the Huffman tree.
class HuffmanNode
{
    private:
    char ch;
    int freq;
    public:
    HuffmanNode* left;
    HuffmanNode* right;
    public:
    HuffmanNode(char ch,int freq,HuffmanNode* leftNode,HuffmanNode* rightNode)
    {
        this->ch=ch;
        this->freq=freq;
        left=leftNode;
        right=rightNode;
    }
    char getCharacter()
    {
        return this->ch;
    }
    int getFreq()
    {
        return freq;
    }
};

//comparator to store the nodes of the tree in the heap according to the frequency
struct comp
{
    bool operator()(HuffmanNode* leftNode,HuffmanNode* rightNode)
    {
        // High-frequency Nodes come at the top of the heap.
        return leftNode->getFreq() > rightNode->getFreq();
    }
};

// Traversing the node of the tree to compute the HuffmanCodes map(which contains character->code as key-value pairs)
void encoding(HuffmanNode* root,string encodedtxt,map<char,string> &HuffmanCodes)
{
    // if root is NULL then we return.
    if(!root) return;

    //if leaf found , we store the encodedtxt in the HuffmanCode map corresponding to the character of the leaf.
    if(!root->left && !root->right) HuffmanCodes[root->getCharacter()]=encodedtxt;

    encoding(root->left,encodedtxt+"0",HuffmanCodes);
    encoding(root->right,encodedtxt+"1",HuffmanCodes);
}

//Here we are decoding the string from the encoded string.
void decoding(HuffmanNode* root,int &ind,string encodedtxt)
{
    if(!root) return;

    //if leaf found we print the character
    if(!root->left && !root->right)
    {
        cout<<root->getCharacter();
        return;
    }
    ind++;
    if(encodedtxt[ind]=='0') decoding(root->left,ind,encodedtxt);
    else decoding(root->right,ind,encodedtxt);

}

//building the Huffman Tree.
void buildHuffmanTree(string txt)
{
    map<char,int> frequencies;//map to store character-> freq as key-value pairs
    // Traversing the original string to compute the the frequencies map 
    for(auto it:txt)
    {
        frequencies[it]++;
    }
    // Declaring a heap to store the tree nodes based on their freq(lowest freq Node comes at top of the heap)
    priority_queue<HuffmanNode*,vector<HuffmanNode*>,comp> HuffmanTree;

    //storing the Tree nodes in the heap
    for(auto it:frequencies)
    {
        HuffmanTree.push(new HuffmanNode(it.first,it.second,NULL,NULL));
    }

    //building the Huffman Tree
    while(HuffmanTree.size()!=1)
    {
        //Removing the two nodes with highest priority i.e least freq form the heap.
        HuffmanNode* left=HuffmanTree.top();
        HuffmanTree.pop();
        HuffmanNode* right=HuffmanTree.top();
        HuffmanTree.pop();

        // Creating a new node with these two nodes as children and freq=sum of freq of the two nodes.
        int sumFreq=left->getFreq() + right->getFreq();
        HuffmanTree.push(new HuffmanNode('\0',sumFreq,left,right));
    }

    // Root pointer stores the root of the huffman tree.
    HuffmanNode* root=HuffmanTree.top();

    map<char,string> HuffmanCodes;
    // Storing the character->code as key-value pair in HuffmanCodes map.
    encoding(root,"",HuffmanCodes);

    //Displaying the Huffman Codes for each character.
    cout<<"Huffman Codes: "<<endl;
    for(auto it:HuffmanCodes)
    {
        cout<<it.first<<": "<<it.second<<endl;
    }
    cout<<endl<<endl;

    cout<<"Text to be compressed:"<<endl<<txt<<endl<<endl;

    //creating the encoded string for the original string by traversing through the original string and HuffnamCodes map.
    string encodedtxt="";
    for(auto it:txt)
    {
        encodedtxt+=HuffmanCodes[it];
    }

    //Displaying the encoded string.
    cout<<"Encoded Text is: \n"<<encodedtxt<<endl<<endl;

    //Decoding the encoded string back to the original string
    int index=-1;
    cout<<"Decoded Text is: \n";
    while(index < encodedtxt.size()-2)
    {
        decoding(root,index,encodedtxt);
    }
    cout<<endl<<endl;

    //Computing the compression Ratio to find out the compression achieved
    int original_size=8*txt.size();
    int compressed_size=ceil(encodedtxt.size()/8);

    double compression_rate=(double)compressed_size*100/original_size;

    cout<<"Compression Achieved: "<<compression_rate<<endl;


}

signed main()
{
    string str;
    getline(cin,str);
    buildHuffmanTree(str);
    return 0;
}

