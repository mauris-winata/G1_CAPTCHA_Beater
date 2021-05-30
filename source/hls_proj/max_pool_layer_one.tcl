############################################################
## This file is generated automatically by Vivado HLS.
## Please DO NOT edit it.
## Copyright (C) 1986-2018 Xilinx, Inc. All Rights Reserved.
############################################################
cd hls_proj
open_project Max_Pool_Co_Sim
set_top max_pool_1
#add_files Fixed_Point/layers/max_pool/max_pool_layer.h
add_files ../max_pool/max_pool_1.cpp
add_files ../util/fixed_point.cpp
#add_files ../max_pool/max_pool.cpp
#add_files Fixed_Point/layers/conv/conv_layer.h
#add_files Fixed_Point/layers/batch_norm/batch_norm_layer.h
#add_files -tb Fixed_Point/layers/weights -cflags "-Wno-unknown-pragmas"
#add_files -tb Fixed_Point/layers/util -cflags "-Wno-unknown-pragmas"
#add_files -tb Fixed_Point/layers/max_pool_test -cflags "-Wno-unknown-pragmas"
#add_files -tb Fixed_Point/layers/golden_outputs -cflags "-Wno-unknown-pragmas"
#add_files -tb Fixed_Point/layers/generated_outputs -cflags "-Wno-unknown-pragmas"
#add_files -tb Fixed_Point/layers/debug_outputs -cflags "-Wno-unknown-pragmas"
#add_files -tb Fixed_Point/layers/conv -cflags "-Wno-unknown-pragmas"
#add_files -tb Fixed_Point/layers/main.cpp -cflags "-Wno-unknown-pragmas"
open_solution "solution1"
set_part {xcvu095-ffvc1517-2-e} -tool vivado
create_clock -period 2.5 -name default
config_compile -no_signed_zeros=0 -unsafe_math_optimizations=0
#config_schedule -effort medium -enable_dsp_full_reg=0 -relax_ii_for_timing=0 -verbose=0
config_bind -effort medium
#config_export -format ip_catalog -rtl verilog -vivado_phys_opt place -vivado_report_level 0
#config_sdx -optimization_level none -target none
set_clock_uncertainty 12.5%
#source "./Max_Pool_Co_Sim/solution1/directives.tcl"
#csim_design
csynth_design
#cosim_design
export_design -rtl verilog -format ip_catalog
