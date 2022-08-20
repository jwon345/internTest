# Objective

At Halter, we need our collars to store commands that direct each collar to perform a specific task. Examples:
- Move a cow from point A to point B
- Hold a cow within an area of interest, i.e. a break on a farm

A command is a data structure that contains all the information necessary for the collar to perform a specific task as above. As a starting point, it must have the following fields:
- command ID, unique identifier
- command type, e.g. whether to move a cow from point A to point B or to hold a cow within a certain area
- command parameters specific to the type

Design a system that can store these types of commands in a way that allows for:
- performant (fast) lookups
- efficiency, consuming the least amount of memory
- easy to add new types of commands

## Requirements

- You can choose to implement this in C or C++, whichever language you are more comfortable with

## Constraints

Most embedded systems have hard constraints, whether it be limited memory, real-timeness, power etc. However, for this project, we want you to focus on one of them - limited memory. This is a trade-off us embedded/firmware folks frequently make. Hence:

- You CANNOT use dynamic memory (i.e. malloc/calloc/new etc.) and must statically and deterministically allocate all memory
- Do not use any C++ containers/data structures (e.g. std::string, std::map etc.) or third-party libraries that use dynamic memory under the hood

## Deliverables:

- Your implementation, which could be one or multiple files in the include/source directories
- Tests that demonstrate how your design/implementation works
- A readme explaining your key design choices and any other relevant information

We've included a template for tests using doctest. Feel free to use these or use your own framework (gtest, catch2, cpputest...) if you prefer.

# Build instructions

## System Requirements

You'll need a C++ compiler (tested on gcc11),  CMake and Make.

Installing those should be easy on Unix based machines; install from your package manager (apt for ubuntu, pacman for arch, brew for mac, etc).

If you're using Windows, we suggest using WSL and installing a version of Linux and use that with VSCode or your favourite editor.

## The Makefile

The project is configured as a CMake project, which isn't the easiest to wrap your head around if you've not used it before. So we've included a Makefile which wraps around the CMake commands.

If you're using the existing template, you can type in the project folder the following

**Build and run all the tests.**

`$make test`

# Debug

Feel free to use your favourite IDE/Editor. Although we've set up a a VSCode workspace with debug configurations for linux environment.
First install the recommended extensions in the workspace.

1. Open the workspace using vscode by clicking File -> Open Workspace
2. Select `.vscode/intern-tech-test.code-workspace`
3. Left under `Run and Debug` there are two configurations which will either attach to the main or the test programs.

# Submission

Create an archive of the repository like so:
`git bundle create <filename> master`

And email your completed project back to us.

Please provide a README on how to run your project, including any dependencies.

# Code of Honour

- When accepting and subsequently submitting this project to Halter, you agree that you have not plagiarised any code from any other source (online, another person etc.). If you do end up using some open source library/project for inspiration, be very explicit about this and tell us why.
- You agree to keep this challenge confidential and not release any details about it to any other person(s), or any other source (online or otherwise).
- Essentially, we want to know what YOU can do, ultimately we want to hire the best people, that fit with our culture and our vision for the future. If we make a hire acting on information that isn't truthful, then it will make your job more difficult, as you may not have the skills for the role.
- Any violation of the above clauses will result in an immediate termination of the interview process.

# Assessment Criteria

Your entire assignment will be judged holistically and there is no strict marking rubric, however, we will be taking the following into account when assessing your application:

- Appropriate documentation explaining the design choices you made
- Clean, readable, efficient/performant and extensible code with well-commented APIs
- Appropriate error/exception handling
- Clean, readable unit tests

You have 48 hours to complete the assessment, starting from when you receive the assessment.

# Questions

Please email us if you have any questions at all.
