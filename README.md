# Infineon Test Project

This is a multithreaded C++ application developed using the Qt framework. The project demonstrates thread management.

## Prerequisites

Ensure the following dependencies are installed:

- **Qt** (version X.X.X or higher)
- **C++ compiler** (e.g., g++, clang, MSVC)
- **Qt Creator** (optional, for easier project management)

- ## Installation

1. Clone the repository:
   ```bash
   git clone https://github.com/Kleefeelf/infineon_test.git
   cd infineon_test
   ```
2. Open the project in Qt Creator:
  Open inf_test.pro in Qt Creator.
3. Install any necessary dependencies based on your Qt configuration (e.g., qmake or cmake).

## Building the Project
- If using Qt Creator, simply press the "Run" button after opening the project to build and run.
- Alternatively, from the command line, you can build using qmake or cmake:

```bash
qmake inf_test.pro
make ./inf_test
```

Running the Application
Once the project is built, execute the resulting binary. The application will demonstrate multithreaded task generation with a user interface.
