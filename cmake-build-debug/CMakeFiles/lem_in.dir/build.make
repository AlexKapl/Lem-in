# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.7

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /nfs/2016/a/akaplyar/CLionProjects/lem_in

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /nfs/2016/a/akaplyar/CLionProjects/lem_in/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/lem_in.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/lem_in.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/lem_in.dir/flags.make

CMakeFiles/lem_in.dir/main.c.o: CMakeFiles/lem_in.dir/flags.make
CMakeFiles/lem_in.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/nfs/2016/a/akaplyar/CLionProjects/lem_in/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/lem_in.dir/main.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/lem_in.dir/main.c.o   -c /nfs/2016/a/akaplyar/CLionProjects/lem_in/main.c

CMakeFiles/lem_in.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/lem_in.dir/main.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /nfs/2016/a/akaplyar/CLionProjects/lem_in/main.c > CMakeFiles/lem_in.dir/main.c.i

CMakeFiles/lem_in.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/lem_in.dir/main.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /nfs/2016/a/akaplyar/CLionProjects/lem_in/main.c -o CMakeFiles/lem_in.dir/main.c.s

CMakeFiles/lem_in.dir/main.c.o.requires:

.PHONY : CMakeFiles/lem_in.dir/main.c.o.requires

CMakeFiles/lem_in.dir/main.c.o.provides: CMakeFiles/lem_in.dir/main.c.o.requires
	$(MAKE) -f CMakeFiles/lem_in.dir/build.make CMakeFiles/lem_in.dir/main.c.o.provides.build
.PHONY : CMakeFiles/lem_in.dir/main.c.o.provides

CMakeFiles/lem_in.dir/main.c.o.provides.build: CMakeFiles/lem_in.dir/main.c.o


CMakeFiles/lem_in.dir/reader.c.o: CMakeFiles/lem_in.dir/flags.make
CMakeFiles/lem_in.dir/reader.c.o: ../reader.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/nfs/2016/a/akaplyar/CLionProjects/lem_in/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/lem_in.dir/reader.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/lem_in.dir/reader.c.o   -c /nfs/2016/a/akaplyar/CLionProjects/lem_in/reader.c

CMakeFiles/lem_in.dir/reader.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/lem_in.dir/reader.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /nfs/2016/a/akaplyar/CLionProjects/lem_in/reader.c > CMakeFiles/lem_in.dir/reader.c.i

CMakeFiles/lem_in.dir/reader.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/lem_in.dir/reader.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /nfs/2016/a/akaplyar/CLionProjects/lem_in/reader.c -o CMakeFiles/lem_in.dir/reader.c.s

CMakeFiles/lem_in.dir/reader.c.o.requires:

.PHONY : CMakeFiles/lem_in.dir/reader.c.o.requires

CMakeFiles/lem_in.dir/reader.c.o.provides: CMakeFiles/lem_in.dir/reader.c.o.requires
	$(MAKE) -f CMakeFiles/lem_in.dir/build.make CMakeFiles/lem_in.dir/reader.c.o.provides.build
.PHONY : CMakeFiles/lem_in.dir/reader.c.o.provides

CMakeFiles/lem_in.dir/reader.c.o.provides.build: CMakeFiles/lem_in.dir/reader.c.o


CMakeFiles/lem_in.dir/operator.c.o: CMakeFiles/lem_in.dir/flags.make
CMakeFiles/lem_in.dir/operator.c.o: ../operator.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/nfs/2016/a/akaplyar/CLionProjects/lem_in/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/lem_in.dir/operator.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/lem_in.dir/operator.c.o   -c /nfs/2016/a/akaplyar/CLionProjects/lem_in/operator.c

CMakeFiles/lem_in.dir/operator.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/lem_in.dir/operator.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /nfs/2016/a/akaplyar/CLionProjects/lem_in/operator.c > CMakeFiles/lem_in.dir/operator.c.i

CMakeFiles/lem_in.dir/operator.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/lem_in.dir/operator.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /nfs/2016/a/akaplyar/CLionProjects/lem_in/operator.c -o CMakeFiles/lem_in.dir/operator.c.s

CMakeFiles/lem_in.dir/operator.c.o.requires:

.PHONY : CMakeFiles/lem_in.dir/operator.c.o.requires

CMakeFiles/lem_in.dir/operator.c.o.provides: CMakeFiles/lem_in.dir/operator.c.o.requires
	$(MAKE) -f CMakeFiles/lem_in.dir/build.make CMakeFiles/lem_in.dir/operator.c.o.provides.build
.PHONY : CMakeFiles/lem_in.dir/operator.c.o.provides

CMakeFiles/lem_in.dir/operator.c.o.provides.build: CMakeFiles/lem_in.dir/operator.c.o


CMakeFiles/lem_in.dir/checker.c.o: CMakeFiles/lem_in.dir/flags.make
CMakeFiles/lem_in.dir/checker.c.o: ../checker.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/nfs/2016/a/akaplyar/CLionProjects/lem_in/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/lem_in.dir/checker.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/lem_in.dir/checker.c.o   -c /nfs/2016/a/akaplyar/CLionProjects/lem_in/checker.c

CMakeFiles/lem_in.dir/checker.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/lem_in.dir/checker.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /nfs/2016/a/akaplyar/CLionProjects/lem_in/checker.c > CMakeFiles/lem_in.dir/checker.c.i

CMakeFiles/lem_in.dir/checker.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/lem_in.dir/checker.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /nfs/2016/a/akaplyar/CLionProjects/lem_in/checker.c -o CMakeFiles/lem_in.dir/checker.c.s

CMakeFiles/lem_in.dir/checker.c.o.requires:

.PHONY : CMakeFiles/lem_in.dir/checker.c.o.requires

CMakeFiles/lem_in.dir/checker.c.o.provides: CMakeFiles/lem_in.dir/checker.c.o.requires
	$(MAKE) -f CMakeFiles/lem_in.dir/build.make CMakeFiles/lem_in.dir/checker.c.o.provides.build
.PHONY : CMakeFiles/lem_in.dir/checker.c.o.provides

CMakeFiles/lem_in.dir/checker.c.o.provides.build: CMakeFiles/lem_in.dir/checker.c.o


CMakeFiles/lem_in.dir/hasher.c.o: CMakeFiles/lem_in.dir/flags.make
CMakeFiles/lem_in.dir/hasher.c.o: ../hasher.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/nfs/2016/a/akaplyar/CLionProjects/lem_in/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/lem_in.dir/hasher.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/lem_in.dir/hasher.c.o   -c /nfs/2016/a/akaplyar/CLionProjects/lem_in/hasher.c

CMakeFiles/lem_in.dir/hasher.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/lem_in.dir/hasher.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /nfs/2016/a/akaplyar/CLionProjects/lem_in/hasher.c > CMakeFiles/lem_in.dir/hasher.c.i

CMakeFiles/lem_in.dir/hasher.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/lem_in.dir/hasher.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /nfs/2016/a/akaplyar/CLionProjects/lem_in/hasher.c -o CMakeFiles/lem_in.dir/hasher.c.s

CMakeFiles/lem_in.dir/hasher.c.o.requires:

.PHONY : CMakeFiles/lem_in.dir/hasher.c.o.requires

CMakeFiles/lem_in.dir/hasher.c.o.provides: CMakeFiles/lem_in.dir/hasher.c.o.requires
	$(MAKE) -f CMakeFiles/lem_in.dir/build.make CMakeFiles/lem_in.dir/hasher.c.o.provides.build
.PHONY : CMakeFiles/lem_in.dir/hasher.c.o.provides

CMakeFiles/lem_in.dir/hasher.c.o.provides.build: CMakeFiles/lem_in.dir/hasher.c.o


# Object files for target lem_in
lem_in_OBJECTS = \
"CMakeFiles/lem_in.dir/main.c.o" \
"CMakeFiles/lem_in.dir/reader.c.o" \
"CMakeFiles/lem_in.dir/operator.c.o" \
"CMakeFiles/lem_in.dir/checker.c.o" \
"CMakeFiles/lem_in.dir/hasher.c.o"

# External object files for target lem_in
lem_in_EXTERNAL_OBJECTS =

lem_in: CMakeFiles/lem_in.dir/main.c.o
lem_in: CMakeFiles/lem_in.dir/reader.c.o
lem_in: CMakeFiles/lem_in.dir/operator.c.o
lem_in: CMakeFiles/lem_in.dir/checker.c.o
lem_in: CMakeFiles/lem_in.dir/hasher.c.o
lem_in: CMakeFiles/lem_in.dir/build.make
lem_in: ../libft/libft.a
lem_in: CMakeFiles/lem_in.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/nfs/2016/a/akaplyar/CLionProjects/lem_in/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking C executable lem_in"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/lem_in.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/lem_in.dir/build: lem_in

.PHONY : CMakeFiles/lem_in.dir/build

CMakeFiles/lem_in.dir/requires: CMakeFiles/lem_in.dir/main.c.o.requires
CMakeFiles/lem_in.dir/requires: CMakeFiles/lem_in.dir/reader.c.o.requires
CMakeFiles/lem_in.dir/requires: CMakeFiles/lem_in.dir/operator.c.o.requires
CMakeFiles/lem_in.dir/requires: CMakeFiles/lem_in.dir/checker.c.o.requires
CMakeFiles/lem_in.dir/requires: CMakeFiles/lem_in.dir/hasher.c.o.requires

.PHONY : CMakeFiles/lem_in.dir/requires

CMakeFiles/lem_in.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/lem_in.dir/cmake_clean.cmake
.PHONY : CMakeFiles/lem_in.dir/clean

CMakeFiles/lem_in.dir/depend:
	cd /nfs/2016/a/akaplyar/CLionProjects/lem_in/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /nfs/2016/a/akaplyar/CLionProjects/lem_in /nfs/2016/a/akaplyar/CLionProjects/lem_in /nfs/2016/a/akaplyar/CLionProjects/lem_in/cmake-build-debug /nfs/2016/a/akaplyar/CLionProjects/lem_in/cmake-build-debug /nfs/2016/a/akaplyar/CLionProjects/lem_in/cmake-build-debug/CMakeFiles/lem_in.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/lem_in.dir/depend
