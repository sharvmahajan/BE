#include<bits/stdc++.h>
using namespace std;

struct Node {
    char ch;
    int freq;
    Node *left, *right;

    Node(char c, int f) {
        ch = c;
        freq = f;
        left = right = nullptr;
    }
};

struct Compare {
    bool operator()(Node* a, Node* b) {
        return a->freq > b->freq;
    }
};

void printCodes(Node* root, string code) {
    if (!root)
        return;

    if (!root->left && !root->right) {
        cout << root->ch << " : " << code << endl;
        return;
    }

    printCodes(root->left, code + "0");
    printCodes(root->right, code + "1");
}

void huffmanEncoding() {
    int n;
    cout << "Enter number of characters: ";
    cin >> n;

    if (n <= 0) {
        cout << "Invalid number of characters\n";
        return;
    }

    priority_queue<Node*, vector<Node*>, Compare> pq;

    cout << "Enter character and frequency:\n";

    for (int i = 0; i < n; i++) {
        char ch;
        int freq;
        cin >> ch >> freq;

        if (freq < 0) {
            cout << "Frequency cannot be negative\n";
            return;
        }

        pq.push(new Node(ch, freq));
    }

    while (pq.size() > 1) {
        Node* left = pq.top();
        pq.pop();

        Node* right = pq.top();
        pq.pop();

        Node* parent = new Node('$', left->freq + right->freq);
        parent->left = left;
        parent->right = right;

        pq.push(parent);
    }

    cout << "\nHuffman Codes:\n";
    printCodes(pq.top(), "");
}

int main() {
    string choice;

    while (true) {
        cout << "\n--- Huffman Encoding Menu ---\n";
        cout << "1. Generate Huffman Codes\n";
        cout << "2. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == "1") {
            huffmanEncoding();
        }
        else if (choice == "2") {
            break;
        }
        else {
            cout << "Invalid choice\n";
        }
    }

    return 0;
}