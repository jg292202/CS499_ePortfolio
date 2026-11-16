# Software Engineering ePortfolio

**Python • C++ • MongoDB • Software Architecture • Algorithms • Automated Testing**

This repository contains my Computer Science capstone ePortfolio from Southern New Hampshire University and documents the enhancement of three earlier software projects through a more mature engineering perspective.

Rather than presenting only finished artifacts, the portfolio preserves both the **original and enhanced implementations** to show how I evaluated existing systems, identified limitations, made deliberate improvements, and validated the results.

The three enhancement areas are:

1. **Software Engineering & Design** - architectural refactoring and maintainability
2. **Algorithms & Data Structures** - BST-to-AVL tree enhancement
3. **Databases** - validation, query capabilities, testing, and data-layer design

## ePortfolio Website

The complete ePortfolio, including my professional self-assessment, artifact narratives, code review, and screenshots, is available through GitHub Pages:

**https://jg292202.github.io/CS499_ePortfolio**

---

## Featured Artifacts

### 1. Software Engineering & Design
#### Grazioso Salvare Dashboard

**Python • Dash • MongoDB • Modular Architecture • Automated Testing**

The original Grazioso Salvare dashboard combined a Python/Dash interface with MongoDB-backed CRUD operations.

For the capstone enhancement, I revisited the application with an emphasis on architecture, maintainability, testability, and defensive software design.

Key enhancements include:

- Dedicated service layer
- Improved separation of concerns
- Dependency injection
- Structured logging
- Input validation
- Improved error handling
- Unit testing

**Explore:**

- [Enhancement Narrative](artifacts/software-engineering.md)
- [Original Source](original/software-engineering/)
- [Enhanced Source](enhanced/software-engineering/)
- [Screenshots](screenshots/software-engineering/)

---

### 2. Algorithms & Data Structures
#### Binary Search Tree → AVL Tree

**C++ • AVL Trees • Algorithms • Data Structures • Complexity Analysis**

The original project stored and searched bid records using a traditional binary search tree.

For the capstone enhancement, I converted the unbalanced BST into a self-balancing AVL tree capable of maintaining logarithmic worst-case search and insertion performance.

Key enhancements include:

- Height tracking
- Balance-factor calculation
- LL rotation
- RR rotation
- LR rotation
- RL rotation
- Rebalancing after tree operations
- Enhanced deletion logic

The enhancement demonstrates how structural invariants and balancing operations can improve worst-case tree performance from **O(n)** to **O(log n)**.

**Explore:**

- [Enhancement Narrative](artifacts/algorithms.md)
- [Original BST](original/algorithms/)
- [Enhanced AVL Tree](enhanced/algorithms/)
- [Screenshots](screenshots/algorithms/)

---

### 3. Databases
#### Enhanced CRUD Data Layer

**Python • MongoDB • Validation • Aggregation • Automated Testing**

The database enhancement revisits an earlier MongoDB CRUD module with an emphasis on secure data handling, expanded query capabilities, modularity, and testability.

Key enhancements include:

- Nested validation
- Advanced query handling
- Aggregation pipelines
- Sorting and projection
- Structured logging
- Service-layer separation
- Automated unit testing
- FakeDB/FakeCollection testing support
- Example query workflows

**Explore:**

- [Enhancement Narrative](artifacts/databases.md)
- [Original CRUD Module](original/databases/)
- [Enhanced Data Layer](enhanced/databases/)
- [Screenshots](screenshots/databases/)

---

## Original → Enhanced

A central goal of this portfolio is to demonstrate engineering growth rather than simply present completed assignments.

Each artifact preserves an earlier implementation alongside its enhanced counterpart:

| Area | Original | Enhancement |
|---|---|---|
| Software Engineering | Python/Dash/MongoDB dashboard | Layered architecture, service layer, dependency injection, logging, validation, testing |
| Algorithms | Binary Search Tree | Self-balancing AVL tree with height tracking and rotations |
| Databases | MongoDB CRUD module | Expanded validation, queries, aggregation, modularity, logging, and automated tests |

This structure makes it possible to inspect not only the final result, but also the engineering decisions that transformed the original implementation.

---

## Engineering Approach

One idea connects all three enhancements:

> **Understand the existing system, identify its limitations, make deliberate improvements, test the result, and continue refining the design.**

The capstone gave me an opportunity to apply that process to software I had written earlier in the Computer Science program.

Revisiting previous work helped strengthen my understanding of:

- Separation of concerns
- Maintainable architecture
- Defensive programming
- Automated testing
- Data integrity
- Algorithmic trade-offs
- Debugging and observability
- Technical documentation

These principles continue to influence the backend and secure-software development work I am pursuing today.

---

## Code Review

The capstone began with a code review of the selected artifacts, including analysis of existing functionality, limitations, and planned enhancements.

[View the Code Review](code-review.md)

---

## Repository Structure
