# ead_ai22m003

# Excercise 1
## What is the difference between git and github?
Git is a version control system. Github is a cloud service that used git and its version control.

## Name 3 benefits of a version control system:
 - Version Control: Have different Versions of code, rebase to old version if a newer one doesn't work
 - Collaborate: Work together on code
 - Branches: You can use a branch for a new feature

## Name 3 alternatives to git:
 - Diversion
 - SVN (Subversion)
 - Perforce

## Name 2 differences between git and other version control systems:
 - Distributed vs centralized version control
 - Merging of a Branch

## Name known issues related to game engines (Unreal, Unity) and version control systems:
 - Handling of versions of large files in git can cause problems on local storage of the developer
 - No file locking available (other developers can always change file - also binarys, etc.)
 - No single file versioning available. One is forced to use the latest updates.


# Exercise 2

## Describe a logging system with your own words:
A logging system is used to get useful information output during runtime. Logs can be output to the console or to specified log files. 
On the console one can for example structure logs by categorizing them by giving different severities different colors. For example if an Error is color red one can concentrate on the red messages and find them easy and fast.

## What is the difference between git submodules and git subtrees?
Git submodules are based on a specific commit. Subtrees include the history of the repository. Thereby submodules are smaller in size than subtrees.

## What is a build system in C++? Name 3 build systems:
A build system is used to generate executible files and/or project files for different platforms, e.g. Windows, Mac, Linux, etc.
3 Build systems:
 - CMake
 - Make (GNU)
 - PreMake

## What is a package manager in C++? Name 3 package manager:
A package manager acquires and manages libraries. It is used to maintain used libraries and dependencies so that it is not needed to do it manually.
3 Package managers:
 - vcpkg (Microsoft)
 - conan
 - build2 (build system & package manager)

