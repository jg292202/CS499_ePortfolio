# Joseph Glista | Professional Self-Assessment

Engineering has been the common thread throughout my career, and completing my Computer Science degree gave me a new environment in which to apply that mindset. This ePortfolio captures that transition by showing how I revisited earlier software projects, identified limitations, and deliberately improved their architecture, algorithms, data handling, security, and testing.

Completing my B.S. in Computer Science at Southern New Hampshire University with a focus in Software Engineering strengthened both my technical foundation and the way I approach software development. Throughout the program, I gained experience working with multiple languages, frameworks, databases, and development environments, but the most valuable growth was learning how to evaluate a system as a whole: understanding its requirements, identifying weaknesses, making deliberate changes, testing the result, and clearly communicating the reasoning behind those decisions.

## Software Engineering & Design

My growth in software engineering is best demonstrated by the enhancement of the **Grazioso Salvare dashboard**, originally developed during my Client/Server Development coursework.

The original application combined Python, Dash, MongoDB, and custom CRUD operations to create an interactive, database-backed interface. During the capstone, I revisited that implementation with a stronger understanding of software architecture and maintainability.

I refactored the application toward a layered design with a dedicated service layer, improved separation of concerns, dependency injection, structured logging, stronger input validation and error handling, and automated testing.

This enhancement changed the way I evaluate software. Functionality remains essential, but working software is only the starting point. Maintainability, testability, observability, modularity, and clear boundaries between responsibilities matter because software must remain understandable and adaptable after the initial implementation is complete.

[Explore the Software Engineering Artifact](artifacts/software-engineering.md)

## Algorithms & Data Structures

My algorithms and data structures enhancement began with a C++ binary search tree used to organize and search bid records.

The original implementation provided standard binary search tree operations, but its unbalanced structure could degrade in performance as the shape of the tree changed. During the capstone, I converted the BST into a self-balancing **AVL tree**.

The enhancement required implementing height tracking, balance-factor calculations, and LL, RR, LR, and RL rotations, along with rebalancing behavior surrounding insertion and deletion. This improved worst-case tree operations from linear behavior in a severely unbalanced tree toward the logarithmic performance expected from a balanced AVL structure.

More importantly, the project strengthened my understanding of why algorithmic correctness involves more than producing the correct output. Data structures carry structural invariants and performance characteristics that must be preserved as the system changes. Debugging rotation logic, height propagation, and deletion behavior required careful reasoning about those invariants rather than simply tracing individual lines of code.

[Explore the Algorithms & Data Structures Artifact](artifacts/algorithms.md)

## Databases & Secure Data Handling

The database enhancement revisited an earlier Python/MongoDB CRUD module and expanded it into a more capable, testable, and defensive data-access implementation.

The enhanced version introduced nested validation, additional query capabilities, aggregation pipelines, sorting and projection, structured logging, service-layer separation, and automated tests using a FakeDB/FakeCollection environment.

This work reinforced the importance of treating data boundaries as trust boundaries. Applications should not assume that incoming data is valid simply because it came from an expected interface. Validation, predictable query behavior, error handling, and testing all contribute to maintaining data integrity and reducing unexpected behavior.

The project also strengthened my appreciation for automated testing as an engineering tool. Building repeatable tests around database and service-layer behavior made it possible to verify changes systematically rather than relying solely on manual inspection.

[Explore the Databases Artifact](artifacts/databases.md)

## Problem Solving & Engineering Growth

Although the three artifacts address different areas of computer science, they share the same underlying engineering process:

1. Understand the existing system and its requirements.
2. Identify limitations, risks, or opportunities for improvement.
3. Analyze possible solutions and their trade-offs.
4. Make deliberate changes.
5. Test and evaluate the result.
6. Continue refining the system based on evidence.

That process closely reflects the structured problem-solving approach I developed earlier in my engineering career. Computer science introduced new tools and abstractions, but the underlying discipline remains familiar: understand the system before changing it, look for root causes rather than symptoms, and verify results rather than assuming a change worked.

## Collaboration & Technical Communication

Most of my Computer Science coursework was completed individually, but the program also strengthened skills that matter in collaborative engineering environments.

Requirements had to be interpreted accurately. Technical decisions had to be explained and defended. Instructor feedback had to be evaluated and incorporated. Code reviews required me to examine existing implementations critically, identify opportunities for improvement, and communicate those findings clearly.

Written narratives, technical documentation, presentations, code reviews, and project artifacts also gave me practice communicating technical ideas to different audiences.

Those experiences reinforced that software engineering is not simplymitations exist, and how proposed changes improve the system.

[View the Capstone Code Review](code-review.md)

## Where I Am Now

The capstone represents the conclusion of my Computer Science degree, but not the conclusion of my development as a software engineer.

My current focus is backend software development, particularly APIs, relational databases, authentication and authorization, automated testing, and secure application design. I am continuing to build on the foundation represented in this portfolio through independent software projects and deeper work with modern backend technologies.

Longer term, I am particularly interested in the intersection of software development, security, automation, AI-assisted engineering, and deployment. Those interests are guiding my continued development toward secure software delivery and DevSecOps-oriented engineering.

What I value most from the Computer Science program is not any individual language or framework. Technologies will continue to change. The more durable skill is the ability to approach unfamiliar systems methodically, understand how their pieces interact, learn what is necessary, test assumptions, and improve the system without losing sight of reliability, security, or maintainability.

That is the engineering mindset I bring forward from this portfolio.

---

## Explore the ePortfolio

- artifacts/software-engineering.md
- artifacts/algorithms.md
- artifacts/databases.md
- [Code Review](code-review.md)
- [Screenshot Gallery](screenshots.md)

---

**[View my GitHub Profile](https://github.com/jg292202)**  
**[Connect with me on LinkedIn](https://www.linkedin.com/in/joseph-glista-218a87165/)**
