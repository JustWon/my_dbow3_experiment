# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.2

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
CMAKE_SOURCE_DIR = /home/dongwonshin/Desktop/DBow3

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/dongwonshin/Desktop/DBow3/build2

# Include any dependencies generated for this target.
include utils/CMakeFiles/create_voc_step1.dir/depend.make

# Include the progress variables for this target.
include utils/CMakeFiles/create_voc_step1.dir/progress.make

# Include the compile flags for this target's objects.
include utils/CMakeFiles/create_voc_step1.dir/flags.make

utils/CMakeFiles/create_voc_step1.dir/create_voc_step1.cpp.o: utils/CMakeFiles/create_voc_step1.dir/flags.make
utils/CMakeFiles/create_voc_step1.dir/create_voc_step1.cpp.o: ../utils/create_voc_step1.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/dongwonshin/Desktop/DBow3/build2/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object utils/CMakeFiles/create_voc_step1.dir/create_voc_step1.cpp.o"
	cd /home/dongwonshin/Desktop/DBow3/build2/utils && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/create_voc_step1.dir/create_voc_step1.cpp.o -c /home/dongwonshin/Desktop/DBow3/utils/create_voc_step1.cpp

utils/CMakeFiles/create_voc_step1.dir/create_voc_step1.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/create_voc_step1.dir/create_voc_step1.cpp.i"
	cd /home/dongwonshin/Desktop/DBow3/build2/utils && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/dongwonshin/Desktop/DBow3/utils/create_voc_step1.cpp > CMakeFiles/create_voc_step1.dir/create_voc_step1.cpp.i

utils/CMakeFiles/create_voc_step1.dir/create_voc_step1.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/create_voc_step1.dir/create_voc_step1.cpp.s"
	cd /home/dongwonshin/Desktop/DBow3/build2/utils && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/dongwonshin/Desktop/DBow3/utils/create_voc_step1.cpp -o CMakeFiles/create_voc_step1.dir/create_voc_step1.cpp.s

utils/CMakeFiles/create_voc_step1.dir/create_voc_step1.cpp.o.requires:
.PHONY : utils/CMakeFiles/create_voc_step1.dir/create_voc_step1.cpp.o.requires

utils/CMakeFiles/create_voc_step1.dir/create_voc_step1.cpp.o.provides: utils/CMakeFiles/create_voc_step1.dir/create_voc_step1.cpp.o.requires
	$(MAKE) -f utils/CMakeFiles/create_voc_step1.dir/build.make utils/CMakeFiles/create_voc_step1.dir/create_voc_step1.cpp.o.provides.build
.PHONY : utils/CMakeFiles/create_voc_step1.dir/create_voc_step1.cpp.o.provides

utils/CMakeFiles/create_voc_step1.dir/create_voc_step1.cpp.o.provides.build: utils/CMakeFiles/create_voc_step1.dir/create_voc_step1.cpp.o

# Object files for target create_voc_step1
create_voc_step1_OBJECTS = \
"CMakeFiles/create_voc_step1.dir/create_voc_step1.cpp.o"

# External object files for target create_voc_step1
create_voc_step1_EXTERNAL_OBJECTS =

utils/create_voc_step1: utils/CMakeFiles/create_voc_step1.dir/create_voc_step1.cpp.o
utils/create_voc_step1: utils/CMakeFiles/create_voc_step1.dir/build.make
utils/create_voc_step1: src/libDBoW3.so.0.0.1
utils/create_voc_step1: /usr/local/lib/libopencv_xphoto.so.3.1.0
utils/create_voc_step1: /usr/local/lib/libopencv_xobjdetect.so.3.1.0
utils/create_voc_step1: /usr/local/lib/libopencv_tracking.so.3.1.0
utils/create_voc_step1: /usr/local/lib/libopencv_surface_matching.so.3.1.0
utils/create_voc_step1: /usr/local/lib/libopencv_structured_light.so.3.1.0
utils/create_voc_step1: /usr/local/lib/libopencv_stereo.so.3.1.0
utils/create_voc_step1: /usr/local/lib/libopencv_sfm.so.3.1.0
utils/create_voc_step1: /usr/local/lib/libopencv_saliency.so.3.1.0
utils/create_voc_step1: /usr/local/lib/libopencv_rgbd.so.3.1.0
utils/create_voc_step1: /usr/local/lib/libopencv_reg.so.3.1.0
utils/create_voc_step1: /usr/local/lib/libopencv_plot.so.3.1.0
utils/create_voc_step1: /usr/local/lib/libopencv_optflow.so.3.1.0
utils/create_voc_step1: /usr/local/lib/libopencv_ximgproc.so.3.1.0
utils/create_voc_step1: /usr/local/lib/libopencv_line_descriptor.so.3.1.0
utils/create_voc_step1: /usr/local/lib/libopencv_hdf.so.3.1.0
utils/create_voc_step1: /usr/local/lib/libopencv_fuzzy.so.3.1.0
utils/create_voc_step1: /usr/local/lib/libopencv_dpm.so.3.1.0
utils/create_voc_step1: /usr/local/lib/libopencv_dnn.so.3.1.0
utils/create_voc_step1: /usr/local/lib/libopencv_datasets.so.3.1.0
utils/create_voc_step1: /usr/local/lib/libopencv_text.so.3.1.0
utils/create_voc_step1: /usr/local/lib/libopencv_face.so.3.1.0
utils/create_voc_step1: /usr/local/lib/libopencv_ccalib.so.3.1.0
utils/create_voc_step1: /usr/local/lib/libopencv_bioinspired.so.3.1.0
utils/create_voc_step1: /usr/local/lib/libopencv_bgsegm.so.3.1.0
utils/create_voc_step1: /usr/local/lib/libopencv_aruco.so.3.1.0
utils/create_voc_step1: /usr/local/lib/libopencv_viz.so.3.1.0
utils/create_voc_step1: /usr/local/lib/libopencv_videostab.so.3.1.0
utils/create_voc_step1: /usr/local/lib/libopencv_superres.so.3.1.0
utils/create_voc_step1: /usr/local/lib/libopencv_stitching.so.3.1.0
utils/create_voc_step1: /usr/local/lib/libopencv_xfeatures2d.so.3.1.0
utils/create_voc_step1: /usr/local/lib/libopencv_shape.so.3.1.0
utils/create_voc_step1: /usr/local/lib/libopencv_photo.so.3.1.0
utils/create_voc_step1: /usr/local/lib/libopencv_cudastereo.so.3.1.0
utils/create_voc_step1: /usr/local/lib/libopencv_cudaoptflow.so.3.1.0
utils/create_voc_step1: /usr/local/lib/libopencv_cudaobjdetect.so.3.1.0
utils/create_voc_step1: /usr/local/lib/libopencv_cudalegacy.so.3.1.0
utils/create_voc_step1: /usr/local/lib/libopencv_objdetect.so.3.1.0
utils/create_voc_step1: /usr/local/lib/libopencv_cudaimgproc.so.3.1.0
utils/create_voc_step1: /usr/local/lib/libopencv_cudafeatures2d.so.3.1.0
utils/create_voc_step1: /usr/local/lib/libopencv_cudawarping.so.3.1.0
utils/create_voc_step1: /usr/local/lib/libopencv_cudafilters.so.3.1.0
utils/create_voc_step1: /usr/local/lib/libopencv_cudacodec.so.3.1.0
utils/create_voc_step1: /usr/local/lib/libopencv_cudabgsegm.so.3.1.0
utils/create_voc_step1: /usr/local/lib/libopencv_video.so.3.1.0
utils/create_voc_step1: /usr/local/lib/libopencv_cudaarithm.so.3.1.0
utils/create_voc_step1: /usr/local/lib/libopencv_calib3d.so.3.1.0
utils/create_voc_step1: /usr/local/lib/libopencv_features2d.so.3.1.0
utils/create_voc_step1: /usr/local/lib/libopencv_ml.so.3.1.0
utils/create_voc_step1: /usr/local/lib/libopencv_highgui.so.3.1.0
utils/create_voc_step1: /usr/local/lib/libopencv_videoio.so.3.1.0
utils/create_voc_step1: /usr/local/lib/libopencv_imgcodecs.so.3.1.0
utils/create_voc_step1: /usr/local/lib/libopencv_imgproc.so.3.1.0
utils/create_voc_step1: /usr/local/lib/libopencv_flann.so.3.1.0
utils/create_voc_step1: /usr/local/lib/libopencv_core.so.3.1.0
utils/create_voc_step1: /usr/local/lib/libopencv_cudev.so.3.1.0
utils/create_voc_step1: utils/CMakeFiles/create_voc_step1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable create_voc_step1"
	cd /home/dongwonshin/Desktop/DBow3/build2/utils && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/create_voc_step1.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
utils/CMakeFiles/create_voc_step1.dir/build: utils/create_voc_step1
.PHONY : utils/CMakeFiles/create_voc_step1.dir/build

utils/CMakeFiles/create_voc_step1.dir/requires: utils/CMakeFiles/create_voc_step1.dir/create_voc_step1.cpp.o.requires
.PHONY : utils/CMakeFiles/create_voc_step1.dir/requires

utils/CMakeFiles/create_voc_step1.dir/clean:
	cd /home/dongwonshin/Desktop/DBow3/build2/utils && $(CMAKE_COMMAND) -P CMakeFiles/create_voc_step1.dir/cmake_clean.cmake
.PHONY : utils/CMakeFiles/create_voc_step1.dir/clean

utils/CMakeFiles/create_voc_step1.dir/depend:
	cd /home/dongwonshin/Desktop/DBow3/build2 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/dongwonshin/Desktop/DBow3 /home/dongwonshin/Desktop/DBow3/utils /home/dongwonshin/Desktop/DBow3/build2 /home/dongwonshin/Desktop/DBow3/build2/utils /home/dongwonshin/Desktop/DBow3/build2/utils/CMakeFiles/create_voc_step1.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : utils/CMakeFiles/create_voc_step1.dir/depend

