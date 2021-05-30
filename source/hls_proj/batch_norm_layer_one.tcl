############################################################
## This file is generated automatically by Vivado HLS.
## Please DO NOT edit it.
## Copyright (C) 1986-2017 Xilinx, Inc. All Rights Reserved.
############################################################
cd hls_proj
open_project BatchNorm1.prj
set_top batch_norm1
add_files ../batch_norm/batch_norm1.cpp
add_files ../util/fixed_point.cpp
#add_files ../../util/shared.cpp
#add_files -tb ../batch_norm_test.h
#add_files -tb batch_norm_test1.cpp -cflags "-I. -std=c++0x"
#add_files -tb ../../debug_outputs
#add_files -tb ../../generated_outputs
#add_files -tb ../../golden_outputs
#add_files -tb ../../input_images
#add_files -tb ../../util
#add_files -tb ../../weights
open_solution "solution1"
set_part {xcvu095-ffvc1517-2-e} -tool vivado
create_clock -period 3 -name default
#source "./BatchNorm1.prj/solution2/directives.tcl"
#csim_design -clean -compiler gcc
csynth_design
#cosim_design
export_design -rtl verilog -format ip_catalog
