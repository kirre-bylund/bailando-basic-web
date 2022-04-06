# bailando-basic-web
My library for basic c++ web functionality

## Building
### Prerequisites
* CMake > v3.11 - The project is set up using CMake, so that is required to used the build structure provided.
* Make
* Suitable C++ compiler - gcc, clang or MSVC depending on your system.

### How to build?
There is a build script provided that should work on any linux machine with the prerequisites in place: `build.sh`. It will remove the build folder, build the project binary, and then run it.

If that does not work for you, do the following (command line):
1. Create a build folder in the root project directory (if one exists, delete it).
2. Run the command `cmake -S . -B build/`. Watch the build output (if it fails, please contact me).
3. cd into the build folder
4. Run the command `make`. Watch the build output (if it fails, please contact me).
5. You should now have a binary of the appropriate os type named bailando-cmake-base.

If that does not work for you and you do not have a command line (troubleshooting).
* You can use the CMake GUI if you feel more comfortable there. In it you could make it create an IDE project for you to open (for example Visual Studio or XCode). Then you can use that to build. I have not created the project structure to do this so it might require some additional steps to work.
* You can use your own favorite build tool. Nothing magic is done in cmake or the build script. Simply build with main as the executable target and make sure to include all the other cpp files in the src folder together with all the .h files in the inc folder for compilation and linking.
* Contact me
```
	Erik Bylund
	kirre_bylund@hotmail.com
	+46703891989
```

### How to run?
Simply run the executable `build/bailando-basic-web(.exe)` using a command line. The output will be written to std::out.

## Project Structure
### Build System
* CMakeLists.txt - Instructions to CMake on how to build the project.
* build.sh - A build script to make building into a one line command, mainly for me during development.
* src - source file for project
* lib - folder for any included libraries.

### Code
The code is structured into an include folder (inc) containing all the header files and a source folder (src) containing all the source files.