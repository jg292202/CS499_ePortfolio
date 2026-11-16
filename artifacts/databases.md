# Databases & Secure Data Handling

## Enhanced MongoDB CRUD Data Layer

**Python • MongoDB • Validation • Aggregation Pipelines • Structured Logging • Automated Testing**

This artifact began as a Python CRUD module developed during my CS 340 Client/Server Development coursework for interacting with the AAC MongoDB dataset.

The original implementation provided the core create, read, update, and delete operations needed by the application. For my Computer Science capstone, I revisited the data layer with a stronger focus on modularity, validation, query capabilities, observability, security, and testability.

## Original Implementation

The original module provided a functional interface for basic MongoDB operations, including:

- Create
- Read
- Update
- Delete

While the module satisfied the original application requirements, revisiting the implementation revealed opportunities to improve how it handled dependencies, validation, errors, advanced queries, and automated testing.

## Capstone Enhancement

The enhanced data layer expands the original CRUD module into a more modular and testable implementation.

### Dependency Injection

The database dependency can be supplied to the data-access code rather than being tightly coupled to one database connection.

This makes the module more flexible and, importantly, allows test implementations to be substituted without requiring a live MongoDB database.

### Structured Logging

A dedicated logging configuration was added to improve visibility into application behavior.

Logging provides additional context around CRUD operations, query execution, aggregation behavior, and error conditions, making failures easier to diagnose.

### Query Capabilities

The enhanced module expands beyond basic CRUD operations with support for:

- Query filtering
- Projection
- Sorting
- Aggregation pipelines
- Grouping
- Counting
- Aggregate calculations

An `example_queries.py` script demonstrates these capabilities using practical query workflows.

## Defensive Query Validation

A major focus of the enhancement was strengthening validation around MongoDB query input.

The module recursively examines nested query structures, including dictionaries and lists, and rejects selected operators that should not be accepted through the application interface.

Examples include:

- `$where`
- `$eval`
- `$function`

Recursive validation prevents these operators from bypassing checks simply by appearing deeper within a nested query structure.

This enhancement reinforced an important secure-development principle: **data entering a system should be treated as untrusted until it has been validated against the operations the application intentionally supports.**

## Automated Testing

The enhanced module includes automated tests using Python's `unittest` framework.

To make database behavior testable without depending on the course's live MongoDB environment, I created an in-memory FakeDB/FakeCollection test implementation.

The test suite exercises areas including:

- CRUD operations
- Query behavior
- Projection
- Sorting
- Aggregation
- Top-level query validation
- Nested query validation
- Service-layer behavior

Separating the database dependency from the application code made it possible to verify these behaviors repeatedly without depending on an external database connection.

## Example Queries

The enhanced artifact includes `example_queries.py` to demonstrate the expanded data-access functionality through example workflows.

These examples exercise filtering, projection, sorting, aggregation, and validation behavior and provide a practical demonstration of how the enhanced module can be used.

## Engineering Impact

The most important improvement was not any individual query feature. It was changing the data layer into something that could be **isolated, observed, validated, and tested**.

The enhancement strengthened my understanding of:

- Database abstraction
- Dependency injection
- Input validation
- Defensive programming
- Advanced MongoDB querying
- Aggregation pipelines
- Structured logging
- Error handling
- Unit testing
- Test doubles and dependency isolation

It also demonstrated how architectural decisions affect testability. Once the database dependency could be injected, the module no longer required a live database simply to verify application behavior.

That lesson has carried into my later backend work, where I continue to treat data access, validation, testing, and separation of concerns as fundamental parts of application design.

## Development Environment

The original application used the AAC MongoDB dataset within the course development environment.

Because that database environment is not available outside the course environment, the repository focuses on the source code, example queries, and automated test infrastructure used to demonstrate the enhanced data layer.

## Original Artifact

The original CRUD implementation is preserved for comparison:

- [Original CRUD Module](../original/databases/CRUD_Python_Module.py)

## Enhanced Artifact

The enhanced implementation and supporting test infrastructure are available here:

- [Enhanced CRUD Module](../enhanced/databases/CRUD_Python_Module2.py)
- [Example Queries](../enhanced/databases/example_queries.py)
- [Logging Configuration](../enhanced/databases/logging_config.py)
- [Service Layer](../enhanced/databases/service_layer.py)
- [CRUD Module Tests](../enhanced/databases/test_crud_module.py)
- [Service Layer Tests](../enhanced/databases/test_service_layer.py)

## Visual Evidence

Screenshots showing example output, test execution, and application behavior are available in the portfolio gallery.

[View Screenshot Gallery](../screenshots.md)

---

## Continue Exploring

- [ePortfolio Home](../index.md)
- [Software Engineering & Design](software-engineering.md)
- [Algorithms & Data Structures](algorithms.md)
- [Code Review](../code-review.md)
- [Screenshot Gallery](../screenshots.md)
- [Repository Overview](../README.md)
