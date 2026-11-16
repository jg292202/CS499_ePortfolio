# Algorithms & Data Structures

## Binary Search Tree → AVL Tree Enhancement

**C++ • AVL Trees • Binary Search Trees • Data Structures • Complexity Analysis**

This artifact began as a C++ Binary Search Tree (BST) developed during my CS 300 Data Structures and Algorithms coursework. The application loads bid records from CSV data and supports operations for storing, searching, traversing, and managing those records through a tree-based data structure.

For my Computer Science capstone, I revisited the original implementation and converted the unbalanced BST into a self-balancing AVL tree.

The enhancement focused on preserving the behavior of the original application while improving the structural guarantees and worst-case performance of the underlying data structure.

## Original Implementation

The original implementation used a traditional binary search tree to organize bid records.

It demonstrated foundational tree operations including:

- Node insertion
- Tree traversal
- Record search
- Record removal
- CSV-backed data loading

A traditional BST can provide efficient operations when the tree remains reasonably balanced. However, its structure depends on insertion order and can become severely unbalanced.

In the worst case, an unbalanced BST can degenerate toward a linear structure, reducing operations that are normally efficient to **O(n)** behavior.

## Capstone Enhancement

The capstone enhancement converted the original BST into a self-balancing AVL tree.

An AVL tree maintains a balance constraint by tracking subtree heights and reorganizing nodes when an insertion or deletion causes the tree to become unbalanced.

### Height Tracking

Each node's height is tracked so the implementation can determine the relative height of its left and right subtrees.

### Balance Factors

The tree calculates balance factors to detect when a node has moved outside the allowed AVL balance range.

When an imbalance is detected, the tree determines which rotation is required to restore the structure.

### AVL Rotations

The enhanced implementation supports the four standard AVL rotation cases:

- **LL** - Left-Left imbalance
- **RR** - Right-Right imbalance
- **LR** - Left-Right imbalance
- **RL** - Right-Left imbalance

These rotations restructure affected portions of the tree while preserving binary-search ordering.

### Insertion Rebalancing

After inserting a node, the implementation updates subtree heights and evaluates balance factors as control returns through the tree.

When necessary, rotations restore the AVL invariant.

### Deletion Rebalancing

Deletion required additional care because removing a node can affect the height and balance of multiple ancestor nodes.

I revised the original BST deletion logic to account for:

- Standard BST removal behavior
- Successor-node handling
- Height recalculation
- Balance-factor evaluation
- AVL rotations following removal

This was one of the more challenging parts of the enhancement because the tree must remain structurally correct after both the removal itself and the subsequent rebalancing operations.

## Performance Impact

The primary reason for converting the original BST to an AVL tree was to provide stronger performance guarantees.

A severely unbalanced binary search tree can approach:

**O(n)**

for search and insertion operations.

By maintaining a balanced structure, an AVL tree keeps its height proportional to the logarithm of the number of stored nodes, supporting worst-case search and insertion behavior of:

**O(log n)**

The enhancement therefore demonstrates an important algorithmic trade-off: additional work is performed to maintain tree balance in exchange for more predictable operation performance as the dataset grows.

## Engineering Challenges

Implementing AVL balancing required more than adding rotation functions.

The enhancement required careful reasoning about:

- Recursive tree operations
- Structural invariants
- Height propagation
- Balance-factor calculations
- Rotation selection
- Parent and child relationships
- Successor-node behavior during deletion
- Rebalancing after structural changes

Debugging incorrect height calculations and imbalance conditions reinforced the importance of reasoning about the state of the entire data structure rather than focusing only on an individual node or operation.

## What I Learned

This enhancement strengthened my understanding that algorithmic correctness includes both functional behavior and performance characteristics.

The original BST could correctly store and retrieve bid records, but correctness alone did not guarantee predictable performance as the structure changed.

Converting it to an AVL tree required me to think about the invariant that makes the data structure useful: the tree must remain balanced as records are inserted and removed.

That distinction between **working code** and **code that preserves defined performance and structural guarantees** remains an important part of how I evaluate software designs today.

## Original Artifact

The original Binary Search Tree implementation and supporting files are preserved for comparison:

- [Original BST](../original/algorithms/BinarySearchTree_Original.cpp)
- [CSV Parser](../original/algorithms/CSVparser.cpp)
- [CSV Header](../original/algorithms/CSVparser.hpp)
- [Sales Data](../original/algorithms/eBid_Monthly_Sales.csv)
- [December Sales Data](../original/algorithms/eBid_Monthly_Sales_Dec_2016.csv)

## Enhanced Artifact

The enhanced AVL implementation and supporting files are available here:

- [Enhanced AVL Tree](../enhanced/algorithms/BinarySearchTree_EnhancedToAVLTree.cpp)
- [CSV Parser](../enhanced/algorithms/CSVparser.cpp)
- [CSV Header](../enhanced/algorithms/CSVparser.hpp)
- [Sales Data](../enhanced/algorithms/eBid_Monthly_Sales.csv)
- [License File](../enhanced/algorithms/License.txt)

## Visual Evidence

Screenshots demonstrating the enhanced artifact are available in the portfolio gallery.

[View Algorithms Screenshots](../screenshots.md)

---

## Continue Exploring

- [ePortfolio Home](../index.md)
- [Software Engineering & Design](software-engineering.md)
- [Databases & Secure Data Handling](databases.md)
- [Code Review](../code-review.md)
- [Screenshot Gallery](../screenshots.md)
- [Repository Overview](../README.md)
