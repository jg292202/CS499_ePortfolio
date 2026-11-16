# Project Screenshots

This gallery provides visual evidence of the functionality, enhancements, testing, and validation documented throughout the CS 499 ePortfolio.

---

## Software Engineering & Design

### Refactored Grazioso Salvare Dashboard

![Refactored Grazioso Salvare Dashboard](screenshots/software-engineering/Software1.png)

*The enhanced Grazioso Salvare dashboard running in JupyterLab after the software-engineering refactor.*

### Input Validation

![Dashboard Input Validation](screenshots/software-engineering/Software2.png)

*Invalid DataTable filter input (`1 = 1`) is handled without crashing the application. The dashboard returns no matching data rather than attempting to process the invalid filter.*

### Structured Logging

![Structured Application Logging](screenshots/software-engineering/Software3.png)

*Structured application logs include timestamps, log levels, service-layer messages, and information about application activity.*

### Service Layer & Dependency Injection

![Service Layer Implementation](screenshots/software-engineering/Software4.png)

*The `AnimalService` implementation demonstrates the dedicated service layer, validation logic, and injected database dependency introduced during the enhancement.*

### Service-Layer Tests

![Service Layer Test Results](screenshots/software-engineering/Software5.png)

*Automated service-layer test output verifies expected behavior for valid and invalid inputs.*

### Functional Validation After Refactoring

![Dashboard Functional Validation](screenshots/software-engineering/Software6.png)

*The enhanced dashboard continues to update the DataTable, visualization, and map when the Mountain/Wilderness Rescue filter is selected, verifying that functionality was preserved after the architectural refactor.*

---

## Algorithms & Data Structures

### AVL Application Functionality

![AVL Tree Application Functionality](screenshots/algorithms/Algorithms1.png)

*The enhanced AVL-tree implementation preserves the application's original menu-driven operations after replacing the unbalanced binary search tree.*

### AVL Search

![AVL Tree Search Result](screenshots/algorithms/Algorithms2.png)

*The enhanced tree successfully locates the requested bid record using the AVL-based implementation.*

---

## Databases & Secure Data Handling

### Logging Configuration

![Database Logging Configuration](screenshots/databases/Databases1.png)

*The enhanced project structure and `logging_config.py` demonstrate the logging configuration introduced for database and service-layer operations.*

### Advanced Query Examples

![Advanced MongoDB Query Results](screenshots/databases/Databases2.png)

*Console output from `example_queries.py` demonstrates the enhanced module's filtering, projection, sorting, aggregation, and query functionality.*

### Automated CRUD & Validation Tests

![Database Test Results](screenshots/databases/Databases3.png)

*Automated test output from `test_crud_module.py` verifies CRUD behavior, filtering, projection, aggregation, and validation in the enhanced data-access layer.*

---

## Continue Exploring

- [Home](index.md)
- [Software Engineering & Design](artifacts/software-engineering.md)
- [Algorithms & Data Structures](artifacts/algorithms.md)
- [Databases & Secure Data Handling](artifacts/databases.md)
- [Code Review](code-review.md)
- [Repository Overview](README.md)
