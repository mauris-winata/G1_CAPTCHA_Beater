############################################################
## This file is generated automatically by Vivado HLS.
## Please DO NOT edit it.
## Copyright (C) 1986-2018 Xilinx, Inc. All Rights Reserved.
############################################################
cd hls_proj
open_project dense_layer_five.prj
set_top dense_layer_five
add_files ../dense/dense_layer_five.cpp -cflags "-std=c++0x"
add_files ../util/fixed_point.cpp -cflags "-std=c++0x"
#add_files -tb ../dense_test/dense_test.cpp -cflags "-Wno-unknown-pragmas"
#add_files -tb ../util/fixed_point.cpp -cflags "-Wno-unknown-pragmas"
#add_files -tb ../layer_test.cpp -cflags "-Wno-unknown-pragmas"
#add_files -tb ../util/shared.cpp -cflags "-Wno-unknown-pragmas"
open_solution "solution1"
set_part {xcvu095-ffvc1517-2-e} -tool vivado
create_clock -period 4 -name default
config_compile -no_signed_zeros=0 -unsafe_math_optimizations=0
#config_sdx -optimization_level none -target none
config_schedule -effort medium -relax_ii_for_timing=0
#config_export -format ip_catalog -rtl verilog
config_bind -effort medium
set_clock_uncertainty 12.5%
#source "./dense_layer.prj/solution1/directives.tcl"
#csim_design -clean
csynth_design
#cosim_design
#export_design -flow impl -rtl verilog -format ip_catalog
export_design -format ip_catalog
