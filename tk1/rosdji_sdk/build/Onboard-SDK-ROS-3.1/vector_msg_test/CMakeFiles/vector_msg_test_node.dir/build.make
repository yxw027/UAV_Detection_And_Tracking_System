# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

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
CMAKE_SOURCE_DIR = /home/ubuntu/cc/rosdji_sdk/src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ubuntu/cc/rosdji_sdk/build

# Include any dependencies generated for this target.
include Onboard-SDK-ROS-3.1/vector_msg_test/CMakeFiles/vector_msg_test_node.dir/depend.make

# Include the progress variables for this target.
include Onboard-SDK-ROS-3.1/vector_msg_test/CMakeFiles/vector_msg_test_node.dir/progress.make

# Include the compile flags for this target's objects.
include Onboard-SDK-ROS-3.1/vector_msg_test/CMakeFiles/vector_msg_test_node.dir/flags.make

Onboard-SDK-ROS-3.1/vector_msg_test/CMakeFiles/vector_msg_test_node.dir/src/vector_msg_test_node.cpp.o: Onboard-SDK-ROS-3.1/vector_msg_test/CMakeFiles/vector_msg_test_node.dir/flags.make
Onboard-SDK-ROS-3.1/vector_msg_test/CMakeFiles/vector_msg_test_node.dir/src/vector_msg_test_node.cpp.o: /home/ubuntu/cc/rosdji_sdk/src/Onboard-SDK-ROS-3.1/vector_msg_test/src/vector_msg_test_node.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/ubuntu/cc/rosdji_sdk/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object Onboard-SDK-ROS-3.1/vector_msg_test/CMakeFiles/vector_msg_test_node.dir/src/vector_msg_test_node.cpp.o"
	cd /home/ubuntu/cc/rosdji_sdk/build/Onboard-SDK-ROS-3.1/vector_msg_test && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/vector_msg_test_node.dir/src/vector_msg_test_node.cpp.o -c /home/ubuntu/cc/rosdji_sdk/src/Onboard-SDK-ROS-3.1/vector_msg_test/src/vector_msg_test_node.cpp

Onboard-SDK-ROS-3.1/vector_msg_test/CMakeFiles/vector_msg_test_node.dir/src/vector_msg_test_node.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/vector_msg_test_node.dir/src/vector_msg_test_node.cpp.i"
	cd /home/ubuntu/cc/rosdji_sdk/build/Onboard-SDK-ROS-3.1/vector_msg_test && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/ubuntu/cc/rosdji_sdk/src/Onboard-SDK-ROS-3.1/vector_msg_test/src/vector_msg_test_node.cpp > CMakeFiles/vector_msg_test_node.dir/src/vector_msg_test_node.cpp.i

Onboard-SDK-ROS-3.1/vector_msg_test/CMakeFiles/vector_msg_test_node.dir/src/vector_msg_test_node.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/vector_msg_test_node.dir/src/vector_msg_test_node.cpp.s"
	cd /home/ubuntu/cc/rosdji_sdk/build/Onboard-SDK-ROS-3.1/vector_msg_test && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/ubuntu/cc/rosdji_sdk/src/Onboard-SDK-ROS-3.1/vector_msg_test/src/vector_msg_test_node.cpp -o CMakeFiles/vector_msg_test_node.dir/src/vector_msg_test_node.cpp.s

Onboard-SDK-ROS-3.1/vector_msg_test/CMakeFiles/vector_msg_test_node.dir/src/vector_msg_test_node.cpp.o.requires:
.PHONY : Onboard-SDK-ROS-3.1/vector_msg_test/CMakeFiles/vector_msg_test_node.dir/src/vector_msg_test_node.cpp.o.requires

Onboard-SDK-ROS-3.1/vector_msg_test/CMakeFiles/vector_msg_test_node.dir/src/vector_msg_test_node.cpp.o.provides: Onboard-SDK-ROS-3.1/vector_msg_test/CMakeFiles/vector_msg_test_node.dir/src/vector_msg_test_node.cpp.o.requires
	$(MAKE) -f Onboard-SDK-ROS-3.1/vector_msg_test/CMakeFiles/vector_msg_test_node.dir/build.make Onboard-SDK-ROS-3.1/vector_msg_test/CMakeFiles/vector_msg_test_node.dir/src/vector_msg_test_node.cpp.o.provides.build
.PHONY : Onboard-SDK-ROS-3.1/vector_msg_test/CMakeFiles/vector_msg_test_node.dir/src/vector_msg_test_node.cpp.o.provides

Onboard-SDK-ROS-3.1/vector_msg_test/CMakeFiles/vector_msg_test_node.dir/src/vector_msg_test_node.cpp.o.provides.build: Onboard-SDK-ROS-3.1/vector_msg_test/CMakeFiles/vector_msg_test_node.dir/src/vector_msg_test_node.cpp.o

# Object files for target vector_msg_test_node
vector_msg_test_node_OBJECTS = \
"CMakeFiles/vector_msg_test_node.dir/src/vector_msg_test_node.cpp.o"

# External object files for target vector_msg_test_node
vector_msg_test_node_EXTERNAL_OBJECTS =

/home/ubuntu/cc/rosdji_sdk/devel/lib/vector_msg_test/vector_msg_test_node: Onboard-SDK-ROS-3.1/vector_msg_test/CMakeFiles/vector_msg_test_node.dir/src/vector_msg_test_node.cpp.o
/home/ubuntu/cc/rosdji_sdk/devel/lib/vector_msg_test/vector_msg_test_node: Onboard-SDK-ROS-3.1/vector_msg_test/CMakeFiles/vector_msg_test_node.dir/build.make
/home/ubuntu/cc/rosdji_sdk/devel/lib/vector_msg_test/vector_msg_test_node: /opt/ros/indigo/lib/libroscpp.so
/home/ubuntu/cc/rosdji_sdk/devel/lib/vector_msg_test/vector_msg_test_node: /usr/lib/arm-linux-gnueabihf/libboost_signals.so
/home/ubuntu/cc/rosdji_sdk/devel/lib/vector_msg_test/vector_msg_test_node: /usr/lib/arm-linux-gnueabihf/libboost_filesystem.so
/home/ubuntu/cc/rosdji_sdk/devel/lib/vector_msg_test/vector_msg_test_node: /opt/ros/indigo/lib/librosconsole.so
/home/ubuntu/cc/rosdji_sdk/devel/lib/vector_msg_test/vector_msg_test_node: /opt/ros/indigo/lib/librosconsole_log4cxx.so
/home/ubuntu/cc/rosdji_sdk/devel/lib/vector_msg_test/vector_msg_test_node: /opt/ros/indigo/lib/librosconsole_backend_interface.so
/home/ubuntu/cc/rosdji_sdk/devel/lib/vector_msg_test/vector_msg_test_node: /usr/lib/liblog4cxx.so
/home/ubuntu/cc/rosdji_sdk/devel/lib/vector_msg_test/vector_msg_test_node: /usr/lib/arm-linux-gnueabihf/libboost_regex.so
/home/ubuntu/cc/rosdji_sdk/devel/lib/vector_msg_test/vector_msg_test_node: /opt/ros/indigo/lib/libxmlrpcpp.so
/home/ubuntu/cc/rosdji_sdk/devel/lib/vector_msg_test/vector_msg_test_node: /opt/ros/indigo/lib/libroscpp_serialization.so
/home/ubuntu/cc/rosdji_sdk/devel/lib/vector_msg_test/vector_msg_test_node: /opt/ros/indigo/lib/librostime.so
/home/ubuntu/cc/rosdji_sdk/devel/lib/vector_msg_test/vector_msg_test_node: /usr/lib/arm-linux-gnueabihf/libboost_date_time.so
/home/ubuntu/cc/rosdji_sdk/devel/lib/vector_msg_test/vector_msg_test_node: /opt/ros/indigo/lib/libcpp_common.so
/home/ubuntu/cc/rosdji_sdk/devel/lib/vector_msg_test/vector_msg_test_node: /usr/lib/arm-linux-gnueabihf/libboost_system.so
/home/ubuntu/cc/rosdji_sdk/devel/lib/vector_msg_test/vector_msg_test_node: /usr/lib/arm-linux-gnueabihf/libboost_thread.so
/home/ubuntu/cc/rosdji_sdk/devel/lib/vector_msg_test/vector_msg_test_node: /usr/lib/arm-linux-gnueabihf/libpthread.so
/home/ubuntu/cc/rosdji_sdk/devel/lib/vector_msg_test/vector_msg_test_node: /usr/lib/arm-linux-gnueabihf/libconsole_bridge.so
/home/ubuntu/cc/rosdji_sdk/devel/lib/vector_msg_test/vector_msg_test_node: Onboard-SDK-ROS-3.1/vector_msg_test/CMakeFiles/vector_msg_test_node.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable /home/ubuntu/cc/rosdji_sdk/devel/lib/vector_msg_test/vector_msg_test_node"
	cd /home/ubuntu/cc/rosdji_sdk/build/Onboard-SDK-ROS-3.1/vector_msg_test && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/vector_msg_test_node.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
Onboard-SDK-ROS-3.1/vector_msg_test/CMakeFiles/vector_msg_test_node.dir/build: /home/ubuntu/cc/rosdji_sdk/devel/lib/vector_msg_test/vector_msg_test_node
.PHONY : Onboard-SDK-ROS-3.1/vector_msg_test/CMakeFiles/vector_msg_test_node.dir/build

Onboard-SDK-ROS-3.1/vector_msg_test/CMakeFiles/vector_msg_test_node.dir/requires: Onboard-SDK-ROS-3.1/vector_msg_test/CMakeFiles/vector_msg_test_node.dir/src/vector_msg_test_node.cpp.o.requires
.PHONY : Onboard-SDK-ROS-3.1/vector_msg_test/CMakeFiles/vector_msg_test_node.dir/requires

Onboard-SDK-ROS-3.1/vector_msg_test/CMakeFiles/vector_msg_test_node.dir/clean:
	cd /home/ubuntu/cc/rosdji_sdk/build/Onboard-SDK-ROS-3.1/vector_msg_test && $(CMAKE_COMMAND) -P CMakeFiles/vector_msg_test_node.dir/cmake_clean.cmake
.PHONY : Onboard-SDK-ROS-3.1/vector_msg_test/CMakeFiles/vector_msg_test_node.dir/clean

Onboard-SDK-ROS-3.1/vector_msg_test/CMakeFiles/vector_msg_test_node.dir/depend:
	cd /home/ubuntu/cc/rosdji_sdk/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ubuntu/cc/rosdji_sdk/src /home/ubuntu/cc/rosdji_sdk/src/Onboard-SDK-ROS-3.1/vector_msg_test /home/ubuntu/cc/rosdji_sdk/build /home/ubuntu/cc/rosdji_sdk/build/Onboard-SDK-ROS-3.1/vector_msg_test /home/ubuntu/cc/rosdji_sdk/build/Onboard-SDK-ROS-3.1/vector_msg_test/CMakeFiles/vector_msg_test_node.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : Onboard-SDK-ROS-3.1/vector_msg_test/CMakeFiles/vector_msg_test_node.dir/depend

