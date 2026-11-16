# Software Engineering & Design

## Grazioso Salvare Dashboard

**Python • Dash • MongoDB • Service Layer • Dependency Injection • Structured Logging • Automated Testing**

This artifact began as the Grazioso Salvare Dashboard developed during my CS 340 Client/Server Development coursework. The application combines Python, Dash, MongoDB, and custom CRUD operations to provide an interactive interface for viewing and filtering rescue-animal data.

For my Computer Science capstone, I revisited the original implementation from a more mature software-engineering perspective. Rather than adding features for their own sake, I focused on improving the application's architecture, maintainability, testability, validation, and observability.

## Original Implementation

The original application demonstrated several important capabilities:

- Python-based application development
- Dash user-interface components and callbacks
- MongoDB-backed data access
- Custom CRUD operations
- Interactive filtering and data visualization
- Integration between a user interface and persistent data

The application was functional, but revisiting the implementation highlighted opportunities to improve separation of concerns and reduce coupling between user-interface behavior, business logic, and data access.

## Capstone Enhancement

The enhanced version refactors the application toward a more layered and maintainable architecture.

### Service Layer

A dedicated service layer separates application logic from the Dash interface and database-access code.

This improves separation of concerns and gives the application clearer boundaries between presentation, application behavior, and persistence.

### Dependency Injection

Dependencies are supplied to application components rather than tightly coupling those components to concrete implementations.

This reduces coupling and makes individual parts of the application easier to isolate and test.

### Structured Logging

Structured logging was introduced to improve visibility into application behavior and provide more useful information during debugging and troubleshooting.

### Input Validation & Error Handling

Validation and error handling were strengthened around user input and data operations.

These changes help prevent invalid input from propagating through the application and provide more predictable behavior when operations fail.

### Automated Testing

Unit tests were added around the service layer so application behavior could be verified independently from the user interface.

This was an important architectural improvement because testability became part of the design rather than something added only after the implementation was complete.

## Engineering Impact

The most significant lesson from this enhancement was recognizing how tightly coupled code can limit maintainability and testability even when the application itself works.

Refactoring the dashboard required me to think more deliberately about:

- Separation of concerns
- Module responsibilities
- Dependency management
- Defensive programming
- Observability
- Error handling
- Testability
- Regression prevention

The most challenging part of the enhancement was introducing these architectural changes without breaking existing application behavior, particularly around the Dash callbacks.

That experience reinforced an engineering principle that continues to influence my current software work: **functionality is only one measure of software quality**. A system should also be understandable, testable, maintainable, and resilient to change.

## Development Environment

The enhanced artifact was developed and tested in the course's Codio environment using its temporary MongoDB instance.

Because that database environment is not available outside the course environment, the repository contains the source code and supporting tests but does not connect to the original live database.

The artifact is therefore presented primarily as evidence of software architecture, refactoring, testing, and engineering practices rather than as a deployed application.

## Original Artifact

The original implementation is preserved to make the progression from the initial application to the enhanced architecture directly inspectable.

- [Original Dashboard](../original/software-engineering/Dashboard.ipynb)
- [Original CRUD Module](../original/software-engineering/CRUD_Python_Module2.py)
- [Original Grazioso Salvare Logo](../original/software-engineering/Grazioso%20Salvare%20Logo.png)

## Enhanced Artifact

The enhanced implementation contains the refactored dashboard and supporting architectural components.

- [Enhanced Dashboard](../enhanced/software-engineering/Dashboard_Refactored.ipynb)
- [Service Layer](../enhanced/software-engineering/service_layer.py)
- [Logging Configuration](../enhanced/software-engineering/logging_config.py)
- [Unit Tests](../enhanced/software-engineering/test_service_layer.py)
- [Enhanced CRUD Module](../enhanced/software-engineering/CRUD_Python_Module2.py)
- [Enhanced Grazioso Salvare Logo](../enhanced/software-engineering/Grazioso%20Salvare%20Logo.png)

## Visual Evidence

Screenshots of the original and enhanced application are available in the portfolio gallery.

[View Software Engineering Screenshots](../screenshots.md)

---

## Continue Exploring

- [Professional Self-Assessment](../index.md)
- [Algorithms & Data Structures](algorithms.md)
- [Databases](databases.md)
- [Code Review](../code-review.md)
- [Screenshot Gallery](../screenshots.md)
- [GitHub Repository Home](../README.md)
