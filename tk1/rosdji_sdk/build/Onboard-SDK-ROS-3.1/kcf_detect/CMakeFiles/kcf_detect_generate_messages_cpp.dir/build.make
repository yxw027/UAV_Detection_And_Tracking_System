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

# Utility rule file for kcf_detect_generate_messages_cpp.

# Include the progress variables for this target.
include Onboard-SDK-ROS-3.1/kcf_detect/CMakeFiles/kcf_detect_generate_messages_cpp.dir/progress.make

Onboard-SDK-ROS-3.1/kcf_detect/CMakeFiles/kcf_detect_generate_messages_cpp: /home/ubuntu/cc/rosdji_sdk/devel/include/kcf_detect/dectrect.h
Onboard-SDK-ROS-3.1/kcf_detect/CMakeFiles/kcf_detect_generate_messages_cpp: /home/ubuntu/cc/rosdji_sdk/devel/include/kcf_detect/Sendselect.h

/home/ubuntu/cc/rosdji_sdk/devel/include/kcf_detect/dectrect.h: /opt/ros/indigo/share/gencpp/cmake/../../../lib/gencpp/gen_cpp.py
/home/ubuntu/cc/rosdji_sdk/devel/include/kcf_detect/dectrect.h: /home/ubuntu/cc/rosdji_sdk/src/Onboard-SDK-ROS-3.1/kcf_detect/msg/dectrect.msg
/home/ubuntu/cc/rosdji_sdk/devel/include/kcf_detect/dectrect.h: /opt/ros/indigo/share/gencpp/cmake/../msg.h.template
	$(CMAKE_COMMAND) -E cmake_progress_report /home/ubuntu/cc/rosdji_sdk/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold "Generating C++ code from kcf_detect/dectrect.msg"
	cd /home/ubuntu/cc/rosdji_sdk/build/Onboard-SDK-ROS-3.1/kcf_detect && ../../catkin_generated/env_cached.sh /usr/bin/python /opt/ros/indigo/share/gencpp/cmake/../../../lib/gencpp/gen_cpp.py /home/ubuntu/cc/rosdji_sdk/src/Onboard-SDK-ROS-3.1/kcf_detect/msg/dectrect.msg -Ikcf_detect:/home/ubuntu/cc/rosdji_sdk/src/Onboard-SDK-ROS-3.1/kcf_detect/msg -Istd_msgs:/opt/ros/indigo/share/std_msgs/cmake/../msg -p kcf_detect -o /home/ubuntu/cc/rosdji_sdk/devel/include/kcf_detect -e /opt/ros/indigo/share/gencpp/cmake/..

/home/ubuntu/cc/rosdji_sdk/devel/include/kcf_detect/Sendselect.h: /opt/ros/indigo/share/gencpp/cmake/../../../lib/gencpp/gen_cpp.py
/home/ubuntu/cc/rosdji_sdk/devel/include/kcf_detect/Sendselect.h: /home/ubuntu/cc/rosdji_sdk/src/Onboard-SDK-ROS-3.1/kcf_detect/msg/Sendselect.msg
/home/ubuntu/cc/rosdji_sdk/devel/include/kcf_detect/Sendselect.h: /opt/ros/indigo/share/gencpp/cmake/../msg.h.template
	$(CMAKE_COMMAND) -E cmake_progress_report /home/ubuntu/cc/rosdji_sdk/build/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold "Generating C++ code from kcf_detect/Sendselect.msg"
	cd /home/ubuntu/cc/rosdji_sdk/build/Onboard-SDK-ROS-3.1/kcf_detect && ../../catkin_generated/env_cached.sh /usr/bin/python /opt/ros/indigo/share/gencpp/cmake/../../../lib/gencpp/gen_cpp.py /home/ubuntu/cc/rosdji_sdk/src/Onboard-SDK-ROS-3.1/kcf_detect/msg/Sendselect.msg -Ikcf_detect:/home/ubuntu/cc/rosdji_sdk/src/Onboard-SDK-ROS-3.1/kcf_detect/msg -Istd_msgs:/opt/ros/indigo/share/std_msgs/cmake/../msg -p kcf_detect -o /home/ubuntu/cc/rosdji_sdk/devel/include/kcf_detect -e /opt/ros/indigo/share/gencpp/cmake/..

kcf_detect_generate_messages_cpp: Onboard-SDK-ROS-3.1/kcf_detect/CMakeFiles/kcf_detect_generate_messages_cpp
kcf_detect_generate_messages_cpp: /home/ubuntu/cc/rosdji_sdk/devel/include/kcf_detect/dectrect.h
kcf_detect_generate_messages_cpp: /home/ubuntu/cc/rosdji_sdk/devel/include/kcf_detect/Sendselect.h
kcf_detect_generate_messages_cpp: Onboard-SDK-ROS-3.1/kcf_detect/CMakeFiles/kcf_detect_generate_messages_cpp.dir/build.make
.PHONY : kcf_detect_generate_messages_cpp

# Rule to build all files generated by this target.
Onboard-SDK-ROS-3.1/kcf_detect/CMakeFiles/kcf_detect_generate_messages_cpp.dir/build: kcf_detect_generate_messages_cpp
.PHONY : Onboard-SDK-ROS-3.1/kcf_detect/CMakeFiles/kcf_detect_generate_messages_cpp.dir/build

Onboard-SDK-ROS-3.1/kcf_detect/CMakeFiles/kcf_detect_generate_messages_cpp.dir/clean:
	cd /home/ubuntu/cc/rosdji_sdk/build/Onboard-SDK-ROS-3.1/kcf_detect && $(CMAKE_COMMAND) -P CMakeFiles/kcf_detect_generate_messages_cpp.dir/cmake_clean.cmake
.PHONY : Onboard-SDK-ROS-3.1/kcf_detect/CMakeFiles/kcf_detect_generate_messages_cpp.dir/clean

Onboard-SDK-ROS-3.1/kcf_detect/CMakeFiles/kcf_detect_generate_messages_cpp.dir/depend:
	cd /home/ubuntu/cc/rosdji_sdk/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ubuntu/cc/rosdji_sdk/src /home/ubuntu/cc/rosdji_sdk/src/Onboard-SDK-ROS-3.1/kcf_detect /home/ubuntu/cc/rosdji_sdk/build /home/ubuntu/cc/rosdji_sdk/build/Onboard-SDK-ROS-3.1/kcf_detect /home/ubuntu/cc/rosdji_sdk/build/Onboard-SDK-ROS-3.1/kcf_detect/CMakeFiles/kcf_detect_generate_messages_cpp.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : Onboard-SDK-ROS-3.1/kcf_detect/CMakeFiles/kcf_detect_generate_messages_cpp.dir/depend

