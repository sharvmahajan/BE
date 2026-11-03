#include<bits/stdc++.h>
using namespace std;
#define ll long long

class Node{
public:
    char ch;
    ll freq;
    Node *left, *right;
    ll id;
    Node(char c, ll f, ll indx){
        ch = c;
        freq = f;
        id = indx;
        left = NULL;
        right = NULL;
    }
};

class cmp{
public:
    bool operator()(Node* a, Node* b){
        if (a->freq == b->freq) return a->id > b->id;
        return a->freq > b->freq;
    }
};

void dfs(Node* node, string code, map<char, string>& mp){
    if (!node) return;
    if (!node->left && !node->right){
        cout << node->ch << " : " << code << endl;
        mp[node->ch] = code;
        return;
    }
    dfs(node->left, code+'0', mp);
    dfs(node->right, code+'1', mp);
}

void huffmanEncoding(string s){
    map<char, ll> mp;
    for (char c : s) mp[c]++;

    priority_queue<Node*, vector<Node*>, cmp> pq;
    ll i = 0;
    for (auto& it : mp) pq.push(new Node(it.first, it.second, i++));

    while (pq.size() >= 2){
        Node* a = pq.top();
        pq.pop();
        Node* b = pq.top();
        pq.pop();

        Node* par = new Node('$', a->freq + b->freq, i++);
        par->left = a;
        par->right = b;
        pq.push(par);
    }
    map<char, string> codes;
    dfs(pq.top(), "", codes);
    string output = "";
    for (char ch : s){
        output += codes[ch];
    }
    cout << s << " = " << output << endl;
}

int main(){
    string s, ch;
    while (true){
        cout << "\n1. Huffman Encoding" << endl;
        cout << "2. Exit" << endl;
        cin >> ch;
        if (ch == "1"){
            cin >> s;
            huffmanEncoding(s);
        }
        else if(ch == "2"){
            cout << "Exiting..." << endl;
            break;
        }
        else cout << "Invalid Choice" << endl;
    }
}
