//============================================================================
// Name        : BinarySearchTree_EnhancedToAVLTree.cpp
// Author      : Joseph Glista
// Version     : 1.1
// Copyright   : Copyright � 2023 SNHU COCE
// Description : Refactored Binary Search tree to AVL tree for CS499
//============================================================================

#include <iostream>
#include <time.h>
#include "CSVparser.hpp"

using namespace std;

//============================================================================
//           Global definitions visible to all methods and classes
//============================================================================

// forward declarations
double strToDouble(string str, char ch);

// define a structure to hold bid information
struct Bid {
    string bidId; // unique identifier
    string title;
    string fund;
    double amount;
    Bid() {
        amount = 0.0;
    }
};

// Internal structure for tree node
struct Node {
    Bid bid;
    Node* left;
    Node* right;
    int height;

    // default constructor
    Node() {
        left = nullptr;
        right = nullptr;
        height = 1;
    }

    // initialize with a bid
    Node(Bid aBid) :
            Node() {
        bid = aBid;
    }
};

//============================================================================
//                  AVL Search Tree class definition
//============================================================================
//
// Define a class containing data members and methods to
// implement an AVL search tree
// 
class AVLSearchTree {

private:
    Node* root;

    void inOrder(Node* node);
    void postOrder(Node* node);
    void preOrder(Node* node);
    Node* removeNode(Node* node, string bidId);
    Node* insertNode(Node* node, Bid bid);

public:
    AVLSearchTree();
    virtual ~AVLSearchTree();
    void destroyTree(Node* node);               // Adding destroyTree helper function to class
    void InOrder();
    void PostOrder();
    void PreOrder();
    void Insert(Bid bid);
    void Remove(string bidId);
    Bid Search(string bidId);
    
};

//==============================================================
//               CONSTRUCTOR / DESTRUCTOR
//==============================================================
AVLSearchTree::AVLSearchTree() {
    root = nullptr;
}

AVLSearchTree::~AVLSearchTree() {
    destroyTree(root);
}

void AVLSearchTree::destroyTree(Node* node) {            // Helper function to recursively delete left and right nodes.
    if (node != nullptr) {
        destroyTree(node->left);
        destroyTree(node->right);
        delete node;
    }
}

//==============================================================
//              HELPER FUNCTIONS: HEIGHT & BALANCE
//==============================================================
int getHeight(Node* node) {
    if (node == nullptr) return 0;
    return node->height;
}

int getBalance(Node* node) {
    if (node == nullptr) return 0;
    return getHeight(node->left) - getHeight(node->right);
}

//==============================================================
//                   ROTATE RIGHT & LEFT
//==============================================================
Node* rotateRight(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = 1 + max(getHeight(y->left), getHeight(y->right));
    x->height = 1 + max(getHeight(x->left), getHeight(x->right));

    return x;
}

Node* rotateLeft(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    x->right = T2;
    y->left = x;

    x->height = 1 + max(getHeight(x->left), getHeight(x->right));
    y->height = 1 + max(getHeight(y->left), getHeight(y->right));

    return y;
}

//==============================================================
//         AVL INSERT - insertNode() FUNCTION (PRIVATE)
//==============================================================
Node* AVLSearchTree::insertNode(Node* node, Bid bid) {
    if (node == nullptr) {
        return new Node(bid);
    }

    if (bid.bidId < node->bid.bidId) {
        node->left = insertNode(node->left, bid);
    }
    else {
        node->right = insertNode(node->right, bid);
    }

    // Update height
    node->height = 1 + max(getHeight(node->left), getHeight(node->right));

    // Get balance factor
    int balance = getBalance(node);

    // LEFT LEFT CASE
    if (balance > 1 && bid.bidId < node->left->bid.bidId) {
        return rotateRight(node);
    }

    // RIGHT RIGHT CASE
    if (balance < -1 && bid.bidId > node->right->bid.bidId) {
        return rotateLeft(node);
    }

    // LEFT RIGHT CASE
    if (balance > 1 && bid.bidId > node->left->bid.bidId) {
        node->left = rotateLeft(node->left);
        return rotateRight(node);
    }

    // RIGHT LEFT CASE
    if (balance < -1 && bid.bidId < node->right->bid.bidId) {
        node->right = rotateRight(node->right);
        return rotateLeft(node);
    }

    return node;
}

//==============================================================
//         AVL DELETE - removeNode() FUNCTION (PRIVATE)
//==============================================================
//           Remove a bid from some node (recursive)

Node* AVLSearchTree::removeNode(Node* node, string bidId) {
    if (node == nullptr) {                                              // Base case with an empty tree
        return node;
    }
    if (bidId < node->bid.bidId) {                                      // If the bid is smaller, move left
        node->left = removeNode(node->left, bidId);
    }
    else if (bidId > node->bid.bidId) {                                 // If the bid is larger, move right
        node->right = removeNode(node->right, bidId);
    }                                                                   // When a match is found, move forward with deletion
    else {
        if (node->left == nullptr && node->right == nullptr) {          // Leaf node with no children
            delete node;
            return nullptr;
        }
        else if (node->left == nullptr) {                               // One right child and no left child
            Node* temp = node->right;
            delete node;
            return temp;
        }
        else if (node->right == nullptr) {                              // One left child and no right child
            Node* temp = node->left;
            delete node;
            return temp;
        }
        else {                                                          // Two children are present.  Find the in order successor.
            Node* successor = node->right;                              // Move to the leftmost node in the right subtree.
            while (successor->left != nullptr) {
                successor = successor->left;
            }
            node->bid = successor->bid;                                 // Replace current node's bid with successor's bid.
            node->right = removeNode(node->right, successor->bid.bidId);// Recursively remove successor node.
        }
    }

    // Update height
    node->height = 1 + max(getHeight(node->left), getHeight(node->right));

    // Get balance factor
    int balance = getBalance(node);

    // Rebalance cases
    if (balance > 1 && getBalance(node->left) >= 0) {
        return rotateRight(node);
    }

    if (balance > 1 && getBalance(node->left) < 0) {
        node->left = rotateLeft(node->left);
        return rotateRight(node);
    }

    if (balance < -1 && getBalance(node->right) <= 0)
        return rotateLeft(node);

    if (balance < -1 && getBalance(node->right) > 0) {
        node->right = rotateRight(node->right);
        return rotateLeft(node);
    }

    return node;                                                        // Return updated node
}




//==============================================================
//                      PUBLIC INTERFACE
//==============================================================
/*
 * Insert a bid
 */
void AVLSearchTree::Insert(Bid bid) {
    root = insertNode(root, bid);
}

/*
 * Remove a bid
 */
void AVLSearchTree::Remove(string bidId) {
    root = removeNode(root, bidId);
}

/*
 * Search for a bid
 */
Bid AVLSearchTree::Search(string bidId) {
    Node* current = root;                       // Set current equal to root

    while (current != nullptr) {
        if (bidId == current->bid.bidId) {      // If the current node matches the bidId, return it.
            return current->bid;
        }
        else if (bidId < current->bid.bidId) {  // If the bidId is less than the current node, move left.
            current = current->left;
        }
        else {                                  // If the bidId is greater than the current, move right.
            current = current->right;
        }
    }
    Bid bid;                                    // Return empty bid if not found.
    return bid;
}

//==============================================================
//                      TREE TRAVERSALS
//==============================================================
/*
 * Traverse the tree in order
 */
void AVLSearchTree::InOrder() {
    inOrder(root);
}

/*
 * Traverse the tree in post-order
 */
void AVLSearchTree::PostOrder() {
    postOrder(root);
}

/*
 * Traverse the tree in pre-order
 */
void AVLSearchTree::PreOrder() {
    preOrder(root);
}



void AVLSearchTree::inOrder(Node* node) {
    if (node == nullptr) {
        return;
    }

    inOrder(node->left);                    // Traversing in order of left subtree, node, right subtree
    cout << node->bid.bidId << ", "
        << node->bid.title << ", "
        << node->bid.amount << ", "
        << node->bid.fund << endl;
    inOrder(node->right);
}

void AVLSearchTree::postOrder(Node* node) {
    if (node == nullptr) {
        return;
    }
    else if (node != nullptr) {             // Post-order traversal of left subtree, right subtree, node
        postOrder(node->left);
        postOrder(node->right);
        cout << node->bid.bidId << ", "
            << node->bid.title << ", "
            << node->bid.amount << ", "
            << node->bid.fund << endl;
    }
}

void AVLSearchTree::preOrder(Node* node) {
    if (node == nullptr) {
        return;
    }
    else if (node != nullptr) {             // Pre-order traversal of node, left subtree, right subtree
        cout << node->bid.bidId << ", "
            << node->bid.title << ", "
            << node->bid.amount << ", "
            << node->bid.fund << endl;
        preOrder(node->left);
        preOrder(node->right);
    }
}



    


//============================================================================
//                              CSV LOADER
//============================================================================
/*
 * Display the bid information to the console (std::out)
 * 
 * @param bid struct containing the bid info
 */
void displayBid(Bid bid) {
    cout << bid.bidId << ": " << bid.title << " | " << bid.amount << " | "
        << bid.fund << endl;
    return;
}

/*
 * Load a CSV file containing bids into a container
 *
 * @param csvPath the path to the CSV file to load
 * @return a container holding all the bids read
 */
void loadBids(string csvPath, AVLSearchTree* avl) {
    cout << "Loading CSV file " << csvPath << endl;

    // initialize the CSV Parser using the given path
    csv::Parser file = csv::Parser(csvPath);

    // read and display header row - optional
    vector<string> header = file.getHeader();
    for (auto const& c : header) {
        cout << c << " | ";
    }
    cout << "" << endl;

    try {
        // loop to read rows of a CSV file
        for (unsigned int i = 0; i < file.rowCount(); i++) {

            // Create a data structure and add to the collection of bids
            Bid bid;
            bid.bidId = file[i][1];
            bid.title = file[i][0];
            bid.fund = file[i][8];
            bid.amount = strToDouble(file[i][4], '$');

            //cout << "Item: " << bid.title << ", Fund: " << bid.fund << ", Amount: " << bid.amount << endl;

            // push this bid to the end
            avl->Insert(bid);
        }
    }
    catch (csv::Error& e) {
        std::cerr << e.what() << std::endl;
    }
}

/*
 * Simple C function to convert a string to a double
 * after stripping out unwanted char
 *
 * credit: http://stackoverflow.com/a/24875936
 *
 * @param ch The character to strip out
 */
double strToDouble(string str, char ch) {
    str.erase(remove(str.begin(), str.end(), ch), str.end());
    return atof(str.c_str());
}


//============================================================================
//                                  MAIN()
//============================================================================
/*
 * The one and only main() method
 */
int main(int argc, char* argv[]) {

    // process command line arguments
    string csvPath, bidKey;
    switch (argc) {
    case 2:
        csvPath = argv[1];
        bidKey = "98223";
        break;
    case 3:
        csvPath = argv[1];
        bidKey = argv[2];
        break;
    default:
        csvPath = "eBid_Monthly_Sales.csv";
        bidKey = "98223";
    }

    // Define a timer variable
    clock_t ticks;

    // Define an AVL search tree to hold all bids
    AVLSearchTree* avl;
    avl = new AVLSearchTree();
    Bid bid;

    int choice = 0;
    while (choice != 9) {
        cout << "Menu:" << endl;
        cout << "  1. Load Bids" << endl;
        cout << "  2. Display All Bids" << endl;
        cout << "  3. Find Bid" << endl;
        cout << "  4. Remove Bid" << endl;
        cout << "  9. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {

        case 1:
            
            // Initialize a timer variable before loading bids
            ticks = clock();

            // Complete the method call to load the bids
            loadBids(csvPath, avl);

            //cout << avl->Size() << " bids read" << endl;

            // Calculate elapsed time and display result
            ticks = clock() - ticks; // current clock ticks minus starting clock ticks
            cout << "time: " << ticks << " clock ticks" << endl;
            cout << "time: " << ticks * 1.0 / CLOCKS_PER_SEC << " seconds" << endl;
            break;

        case 2:
            avl->InOrder();
            break;

        case 3:
            ticks = clock();

            bid = avl->Search(bidKey);

            ticks = clock() - ticks; // current clock ticks minus starting clock ticks

            if (!bid.bidId.empty()) {
                displayBid(bid);
            } else {
            	cout << "Bid Id " << bidKey << " not found." << endl;
            }

            cout << "time: " << ticks << " clock ticks" << endl;
            cout << "time: " << ticks * 1.0 / CLOCKS_PER_SEC << " seconds" << endl;

            break;

        case 4:
            avl->Remove(bidKey);
            break;
        }
    }

    cout << "Good bye." << endl;

	return 0;
}
