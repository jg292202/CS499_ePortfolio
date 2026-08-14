# Databases

The artifact that I selected for enhancement in Milestone Four is the Python-based CRUD module originally developed in CS340 for interacting with the AAC MongoDB dataset.  I chose this artifact because it represents a foundational component of full-stack development, including secure, reliable, and testable data access.  In its original form, the module provided only basic create, read, update, and delete operations with minimal validation, no logging, and no meaningful error handling. For this milestone, I significantly expanded and hardened this module to meet professional standards and demonstrate competency in software engineering, database design, security, and testing.  These enhancements transformed the artifact from a simple academic exercise into a production-ready data access layer suitable for my ePortfolio.

The first major enhancement involved restructuring the module to use dependency injection, allowing the database client to be passed in rather than hardcoded.  This change improves flexibility, supports mocking during testing, and aligns with modern engineering practices.  I also added structured logging throughout the module using a dedicated logging configuration file, enabling traceability of all CRUD operations, aggregation pipelines, and error conditions. Error handling was expanded to catch and log exceptions consistently, ensuring that failures are visible and diagnosable.  To improve database functionality, I added support for projections, sorting, and aggregation pipelines, allowing the module to perform more advanced queries such as grouping, counting, and averaging fields across the AAC dataset.  These enhancements demonstrate deeper database competency and elevate the module beyond the simple CRUD operations. 

Security was a central focus of my improvements. The original module allowed arbitrary MongoDB queries, including dangerous operators such as $where, $eval, and $function, which can execute server-side JavaScript and pose serious injection risks. I implemented a recursive validation system that inspects every level of a query, including lists, dictionaries, and nested structures, to detect and reject forbidden operators. This nested validation ensures that malicious queries cannot bypass security checks by embedding unsafe operators deep within the query structure.  This enhancement directly supports the CS499 security outcome by demonstrating proactive identification and mitigation of vulnerabilities.

To ensure the module was fully testable, I created a comprehensive unit test suite using Python’s unittest framework.  Because the enhanced module uses dependency injection, I was able to build a complete, in-memory FakeDB, and FakeCollection system that simulates MongoDB’s behavior, including sorting, allowing the tests to exercise the module exactly as real queries would.  The test suite covers all CRUD operations, projections, sorting, aggregation, and both top-level and nested security validation. This demonstrates strong testability and reinforces the reliability of the enhanced module.

Finally, I created an example_queries.py script to showcase the module’s capabilities against the real AAC dataset.  This script demonstrates filtering, projection, sorting, aggregation, and security validation in action, demonstrating that the enhanced module performs correctly in a real-world context. Screenshots of these results, along with unit test output and logging behavior, are included in the artifact ZIP to verify functionality.

Overall, this enhancement process significantly improved the artifact across multiple CS499 outcomes, such as software engineering through improved structure and logging, algorithms and data handling through advanced queries and aggregation, security through nested operator validation, and testing through a complete mock database test suite.  The result is a polished, secure, and professionally engineered database access layer that demonstrates my growth in databases and will make a great addition to my ePortfolio. 

## Original Artifact Files
- [Original CRUD Module (CRUD_Python_Module.py)](../original/databases/CRUD_Python_Module.py)

## Enhanced Artifact Files
- [Enhanced CRUD Module (CRUD_Python_Module2.py)](../enhanced/databases/CRUD_Python_Module2.py)
- [Example Queries](../enhanced/databases/example_queries.py)
- [Logging Configuration](../enhanced/databases/logging_config.py)
- [Service Layer](../enhanced/databases/service_layer.py)
- [Unit Tests (test_crud_module.py)](../enhanced/databases/test_crud_module.py)
- [Service Layer Tests (test_service_layer.py)](../enhanced/databases/test_service_layer.py)

### Navigation
- [Home](../index.md)
- [Software Engineering](software-engineering.md)
- [Algorithms](algorithms.md)
- [Code Review](../code-review.md)
- [Screenshots](../screenshots.md)
