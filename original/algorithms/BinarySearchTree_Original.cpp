//============================================================================
// Name        : BinarySearchTree.cpp
// Author      : Joseph Glista
// Version     : 1.0
// Copyright   : Copyright � 2023 SNHU COCE
// Description : Lab 5-2 Binary Search Tree
//============================================================================

#include <iostream>
#include <time.h>

#include "CSVparser.hpp"

using namespace std;

//============================================================================
// Global definitions visible to all methods and classes
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
    Node *left;
    Node *right;

    // default constructor
    Node() {
        left = nullptr;
        right = nullptr;
    }

    // initialize with a bid
    Node(Bid aBid) :
            Node() {
        bid = aBid;
    }
};

//============================================================================
// Binary Search Tree class definition
//============================================================================

/**
 * Define a class containing data members and methods to
 * implement a binary search tree
 */
class BinarySearchTree {

private:
    Node* root;

    void addNode(Node* node, Bid bid);
    void inOrder(Node* node);
    void postOrder(Node* node);
    void preOrder(Node* node);
    Node* removeNode(Node* node, string bidId);
    

public:
    BinarySearchTree();
    virtual ~BinarySearchTree();
    void destroyTree(Node* node);               // Adding destroyTree helper function to class
    void InOrder();
    void PostOrder();
    void PreOrder();
    void Insert(Bid bid);
    void Remove(string bidId);
    Bid Search(string bidId);
    
};

/**
 * Default constructor
 */
BinarySearchTree::BinarySearchTree() {
    root = nullptr;
}

/**
 * Destructor
 */
BinarySearchTree::~BinarySearchTree() {
    destroyTree(root);
}

void BinarySearchTree::destroyTree(Node* node) {            // Helper function to recursively delete left and right nodes.
    if (node != nullptr) {
        destroyTree(node->left);
        destroyTree(node->right);
        delete node;
    }
}

/**
 * Traverse the tree in order
 */
void BinarySearchTree::InOrder() {
    inOrder(root);
}

/**
 * Traverse the tree in post-order
 */
void BinarySearchTree::PostOrder() {
    postOrder(root);
}

/**
 * Traverse the tree in pre-order
 */
void BinarySearchTree::PreOrder() {
    preOrder(root);
}

/**
 * Insert a bid
 */
void BinarySearchTree::Insert(Bid bid) {
    Node* newNode = new Node(bid);              // Create a new node
    Node* current = root;
    
    if (root == nullptr) {
        root = newNode;                         // If the tree is empty, set the root to the newNode
        return;
    }

    while (true) {                              // If the tree is not empty, find the correct spot to insert.
        if (bid.bidId < current->bid.bidId) {   // If the bidId is less than the current node bidId, go left and search for a spot.
            if (current->left == nullptr) {
                current->left = newNode;        // If the next node on the left is empty, place the bidId in the newNode
                break;
            }
            else {
                current = current->left;        // Move left
            }
        }
        else {
            if (current->right == nullptr) {    // If the right node is empty, place the bidId in the newNode.
                current->right = newNode;
                break;
            }
            else {
                current = current->right;       // Move right
            }
        }
    }
}

/**
 * Remove a bid
 */
void BinarySearchTree::Remove(string bidId) {
    Node* current = root;                                                   // Begin at the root
    Node* parent = nullptr;                                                 // Track parent to reconnect tree after deletion.

    while (current != nullptr) {
        if (bidId == current->bid.bidId) {                                  
            if (current->left == nullptr && current->right == nullptr) {    // If the node is a leaf:
                if (parent == nullptr) {                                        
                    root = nullptr;                                         // Node is the root
                }
                else if (parent->left == current) {                         // If the left node of the parent equals the current node, then set the left to nullptr.
                    parent->left = nullptr;
                }
                else {                                                      // Otherwise set the right node of the parent to nullptr.
                    parent->right = nullptr;
                }
                delete current;                                             // Delete the current node.
            }
            else if (current->right == nullptr) {                           // If there is only a left child, follow similar procedure as above.
                if (parent == nullptr) {
                    root = current->left;
                }
                else if (parent->left == current) {
                    parent->left = current->left;
                }
                else {
                    parent->right = current->left;
                }
            }
            else {                                                          // If there is only a right child OR two children
                Node* successor = current->right;                           // Declare a successor and set it equal to the right node of the current node.
                Node* successorParent = current;                            // Declare a successorParent and set it equal to the current node.
                while (successor->left != nullptr) {
                    successorParent = successor;
                    successor = successor->left;
                }
                current->bid = successor->bid;                              // Replace current bid with successor's bid

                if (successorParent->left == successor) {                   // Remove the successor mode by re-linking successor's parent to successor's right child.
                    successorParent->left = successor->right;
                }
                else {
                    successorParent->right = successor->right;
                }
                delete successor;
            }
            return;                                                         // Node found and removed
        }
        else if (bidId < current->bid.bidId) {                              // If the bidId is less than the current node, move right.
            current = current->left;
        }
        else {                                                              // If the bidId is greater than the current, move left.
            current = current->right;
        }
    }
}

/**
 * Search for a bid
 */
Bid BinarySearchTree::Search(string bidId) {
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

/**
 * Add a bid to some node (recursive)
 *
 * @param node Current node in tree
 * @param bid Bid to be added
 */
void BinarySearchTree::addNode(Node* node, Bid bid) {
    if (bid.bidId < node->bid.bidId) {
        if (node->left == nullptr) {                // If left child doesn't exist, insert here
            node->left = new Node(bid);
        }
        else {
            addNode(node->left, bid);               // Otherwise recursively call addNode with the left node and bid
        }
    }
    else {
        if (node->right == nullptr) {               // If right child doesn't exist, insert here
            node->right = new Node(bid);
        }
        else {
            addNode(node->right, bid);              // Otherwise recursively call addNode with the right node and bid
        }
    }
}

void BinarySearchTree::inOrder(Node* node) {
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

void BinarySearchTree::postOrder(Node* node) {
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

void BinarySearchTree::preOrder(Node* node) { 
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

/**
 * Remove a bid from some node (recursive)
 */
Node* BinarySearchTree::removeNode(Node* node, string bidId) {
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
    return node;                                                        // Return updated node
}
   

    


//============================================================================
// Static methods used for testing
//============================================================================

/**
 * Display the bid information to the console (std::out)
 *
 * @param bid struct containing the bid info
 */
void displayBid(Bid bid) {
    cout << bid.bidId << ": " << bid.title << " | " << bid.amount << " | "
            << bid.fund << endl;
    return;
}

/**
 * Load a CSV file containing bids into a container
 *
 * @param csvPath the path to the CSV file to load
 * @return a container holding all the bids read
 */
void loadBids(string csvPath, BinarySearchTree* bst) {
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
            bst->Insert(bid);
        }
    } catch (csv::Error &e) {
        std::cerr << e.what() << std::endl;
    }
}

/**
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

/**
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

    // Define a binary search tree to hold all bids
    BinarySearchTree* bst;
    bst = new BinarySearchTree();
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
            loadBids(csvPath, bst);

            //cout << bst->Size() << " bids read" << endl;

            // Calculate elapsed time and display result
            ticks = clock() - ticks; // current clock ticks minus starting clock ticks
            cout << "time: " << ticks << " clock ticks" << endl;
            cout << "time: " << ticks * 1.0 / CLOCKS_PER_SEC << " seconds" << endl;
            break;

        case 2:
            bst->InOrder();
            break;

        case 3:
            ticks = clock();

            bid = bst->Search(bidKey);

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
            bst->Remove(bidKey);
            break;
        }
    }

    cout << "Good bye." << endl;

	return 0;
}
