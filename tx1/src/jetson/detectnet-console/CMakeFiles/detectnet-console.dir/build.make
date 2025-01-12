# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/ubuntu/hj/workspace/jetson-inference-ros

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ubuntu/hj/workspace/jetson-inference-ros

# Include any dependencies generated for this target.
include detectnet-console/CMakeFiles/detectnet-console.dir/depend.make

# Include the progress variables for this target.
include detectnet-console/CMakeFiles/detectnet-console.dir/progress.make

# Include the compile flags for this target's objects.
include detectnet-console/CMakeFiles/detectnet-console.dir/flags.make

detectnet-console/CMakeFiles/detectnet-console.dir/detectnet-console.cpp.o: detectnet-console/CMakeFiles/detectnet-console.dir/flags.make
detectnet-console/CMakeFiles/detectnet-console.dir/detectnet-console.cpp.o: detectnet-console/detectnet-console.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/hj/workspace/jetson-inference-ros/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object detectnet-console/CMakeFiles/detectnet-console.dir/detectnet-console.cpp.o"
	cd /home/ubuntu/hj/workspace/jetson-inference-ros/detectnet-console && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/detectnet-console.dir/detectnet-console.cpp.o -c /home/ubuntu/hj/workspace/jetson-inference-ros/detectnet-console/detectnet-console.cpp

detectnet-console/CMakeFiles/detectnet-console.dir/detectnet-console.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/detectnet-console.dir/detectnet-console.cpp.i"
	cd /home/ubuntu/hj/workspace/jetson-inference-ros/detectnet-console && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ubuntu/hj/workspace/jetson-inference-ros/detectnet-console/detectnet-console.cpp > CMakeFiles/detectnet-console.dir/detectnet-console.cpp.i

detectnet-console/CMakeFiles/detectnet-console.dir/detectnet-console.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/detectnet-console.dir/detectnet-console.cpp.s"
	cd /home/ubuntu/hj/workspace/jetson-inference-ros/detectnet-console && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ubuntu/hj/workspace/jetson-inference-ros/detectnet-console/detectnet-console.cpp -o CMakeFiles/detectnet-console.dir/detectnet-console.cpp.s

detectnet-console/CMakeFiles/detectnet-console.dir/detectnet-console.cpp.o.requires:

.PHONY : detectnet-console/CMakeFiles/detectnet-console.dir/detectnet-console.cpp.o.requires

detectnet-console/CMakeFiles/detectnet-console.dir/detectnet-console.cpp.o.provides: detectnet-console/CMakeFiles/detectnet-console.dir/detectnet-console.cpp.o.requires
	$(MAKE) -f detectnet-console/CMakeFiles/detectnet-console.dir/build.make detectnet-console/CMakeFiles/detectnet-console.dir/detectnet-console.cpp.o.provides.build
.PHONY : detectnet-console/CMakeFiles/detectnet-console.dir/detectnet-console.cpp.o.provides

detectnet-console/CMakeFiles/detectnet-console.dir/detectnet-console.cpp.o.provides.build: detectnet-console/CMakeFiles/detectnet-console.dir/detectnet-console.cpp.o


# Object files for target detectnet-console
detectnet__console_OBJECTS = \
"CMakeFiles/detectnet-console.dir/detectnet-console.cpp.o"

# External object files for target detectnet-console
detectnet__console_EXTERNAL_OBJECTS =

aarch64/bin/detectnet-console: detectnet-console/CMakeFiles/detectnet-console.dir/detectnet-console.cpp.o
aarch64/bin/detectnet-console: detectnet-console/CMakeFiles/detectnet-console.dir/build.make
aarch64/bin/detectnet-console: /usr/local/cuda-8.0/lib64/libcudart_static.a
aarch64/bin/detectnet-console: /usr/lib/aarch64-linux-gnu/librt.so
aarch64/bin/detectnet-console: aarch64/lib/libjetson-inference.so
aarch64/bin/detectnet-console: /usr/local/cuda-8.0/lib64/libcudart_static.a
aarch64/bin/detectnet-console: /usr/lib/aarch64-linux-gnu/librt.so
aarch64/bin/detectnet-console: /usr/lib/aarch64-linux-gnu/libQtGui.so
aarch64/bin/detectnet-console: /usr/lib/aarch64-linux-gnu/libQtCore.so
aarch64/bin/detectnet-console: detectnet-console/CMakeFiles/detectnet-console.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ubuntu/hj/workspace/jetson-inference-ros/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ../aarch64/bin/detectnet-console"
	cd /home/ubuntu/hj/workspace/jetson-inference-ros/detectnet-console && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/detectnet-console.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
detectnet-console/CMakeFiles/detectnet-console.dir/build: aarch64/bin/detectnet-console

.PHONY : detectnet-console/CMakeFiles/detectnet-console.dir/build

detectnet-console/CMakeFiles/detectnet-console.dir/requires: detectnet-console/CMakeFiles/detectnet-console.dir/detectnet-console.cpp.o.requires

.PHONY : detectnet-console/CMakeFiles/detectnet-console.dir/requires

detectnet-console/CMakeFiles/detectnet-console.dir/clean:
	cd /home/ubuntu/hj/workspace/jetson-inference-ros/detectnet-console && $(CMAKE_COMMAND) -P CMakeFiles/detectnet-console.dir/cmake_clean.cmake
.PHONY : detectnet-console/CMakeFiles/detectnet-console.dir/clean

detectnet-console/CMakeFiles/detectnet-console.dir/depend:
	cd /home/ubuntu/hj/workspace/jetson-inference-ros && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ubuntu/hj/workspace/jetson-inference-ros /home/ubuntu/hj/workspace/jetson-inference-ros/detectnet-console /home/ubuntu/hj/workspace/jetson-inference-ros /home/ubuntu/hj/workspace/jetson-inference-ros/detectnet-console /home/ubuntu/hj/workspace/jetson-inference-ros/detectnet-console/CMakeFiles/detectnet-console.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : detectnet-console/CMakeFiles/detectnet-console.dir/depend

