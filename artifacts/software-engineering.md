# Software Design & Engineering

The artifact that I selected for enhancement is the CS340 Grazioso Salvare Dashboard, originally created as part of my Client/Server Development coursework.  The dashboard integrates Python, Dash, MongoDB, and custom CRUD operations to visualize rescue animal data.  It was one of the first projects in which I built a functional web-based data interface backed by a live database.  Because it already demonstrated meaningful work in software engineering, data handling, and user-interface design, it was a strong candidate for inclusion in my ePortfolio.  Enhancing this artifact allowed me to revisit the original implementation with a more mature engineering perspective and apply the professional practices I’ve developed throughout my coursework at SNHU.

I chose this artifact because it showcases several core competencies expected from a software engineer, including designing modular systems, implementing secure and maintainable code, working with databases, and building interactive user interfaces.  The enhancements I performed significantly strengthened the artifact’s alignment with industry standards.  The enhanced artifact was developed and tested within the Codio environment, which provides a temporary MongoDB instance. Because this database is not accessible outside Codio, the submitted artifact includes all code but will not connect to a live database. I refactored the dashboard into a layered architecture using a dedicated service layer, added dependency injection, implemented structured logging, introduced robust input validation, and improved error handling.  I also added unit tests to support maintainability and reliability.

The enhancements I completed focused exclusively on the software design and engineering category.  The refactoring of the original code into a service-oriented architecture was the most impactful change, as it separated business logic from the user interface and made the system easier to maintain and extend.  Adding validation and error handling strengthened the reliability of the application and ensured that user input and database interactions were handled safely.  Implementing structured logging improved observability and made the system easier to debug and monitor. Together, these enhancements demonstrate my ability to evaluate an existing system and apply modern engineering techniques. 

These enhancements align directly with the outcome of using proper techniques, skills, and tools to implement computing solutions that deliver value and meet industry expectations.  Enhancing this artifact taught me to review previously written code with a more seasoned and experienced mindset. One of the biggest lessons was recognizing how tightly-coupled logic can limit flexibility and maintainability. Refactoring the dashboard into a service-oriented architecture required me to think carefully about proper separation of concerns and how each part of the system should interact.  Implementing validation and error handling reinforced the importance of defensive programming, especially when dealing with user input and external data sources.  Adding unit tests helped me appreciate the value of testability and how it supports long-term reliability. The most significant challenge I faced was ensuring that new architectural changes did not break existing functionality, particularly in the Dash callbacks. Working through these challenges certainly built my confidence in applying professional engineering techniques and improved my ability to produce clean, maintainable and secure code. 
	
Overall, the enhancement process improved my understanding of software design and engineering and reinforced the skills I will need in my professional career. The improved artifact now reflects my current abilities as a software engineer and demonstrates my growth throughout my coursework.   


## Original Artifact Files
- [Original Dashboard (Dashboard.ipynb)](../original/software-engineering/Dashboard.ipynb)
- [Original CRUD Module (CRUD_Python_Module2.py)](../original/software-engineering/CRUD_Python_Module2.py)
- [Logo](../original/software-engineering/Grazioso%20Salvare%20Logo.png)

## Enhanced Artifact Files
- [Enhanced Dashboard (Dashboard_Refactored.ipynb)](../enhanced/software-engineering/Dashboard_Refactored.ipynb)
- [Service Layer](../enhanced/software-engineering/service_layer.py)
- [Logging Configuration](../enhanced/software-engineering/logging_config.py)
- [Unit Tests (test_service_layer.py)](../enhanced/software-engineering/test_service_layer.py)
- [Enhanced CRUD Module](../enhanced/software-engineering/CRUD_Python_Module2.py)
- [Logo](../enhanced/software-engineering/Grazioso%20Salvare%20Logo.png)

### Navigation
- [Home](../index.md)
- [Algorithms](algorithms.md)
- [Databases](databases.md)
- [Code Review](../code-review.md)
- [Screenshots](../screenshots.md)

