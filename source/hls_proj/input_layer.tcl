############################################################
## This file is generated automatically by Vivado HLS.
## Please DO NOT edit it.
## Copyright (C) 1986-2017 Xilinx, Inc. All Rights Reserved.
############################################################
cd hls_proj
open_project Input_Layer
set_top input_layer
add_files ../util/fixed_point.cpp
add_files ../input/input_layer.cpp
#add_files ../util/shared.cpp
#add_files -tb input_test/input_test.cpp -cflags "-I. -std=c++0x"
#add_files -tb input_test/input_test.h
#add_files -tb ../debug_outputs
#add_files -tb ../generated_outputs
#add_files -tb ../golden_outputs
#add_files -tb ../input_images
#add_files -tb ../util
#add_files -tb ../weights
open_solution "solution1"
set_part {xcvu095-ffvc1517-2-e} -tool vivado
create_clock -period 4 -name default
#source "./Input_Layer/solution1/directives.tcl"
#csim_design -compiler gcc
csynth_design
#cosim_design
export_design -rtl verilog -format ip_catalog
