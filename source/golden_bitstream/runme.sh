#!/bin/sh

# 
# Vivado(TM)
# runme.sh: a Vivado-generated Runs Script for UNIX
# Copyright 1986-2017 Xilinx, Inc. All Rights Reserved.
# 

if [ -z "$PATH" ]; then
  PATH=/opt/mnt/Xilinx/SDK/2017.2/bin:/opt/mnt/Xilinx/Vivado/2017.2/ids_lite/ISE/bin/lin64:/opt/mnt/Xilinx/Vivado/2017.2/bin
else
  PATH=/opt/mnt/Xilinx/SDK/2017.2/bin:/opt/mnt/Xilinx/Vivado/2017.2/ids_lite/ISE/bin/lin64:/opt/mnt/Xilinx/Vivado/2017.2/bin:$PATH
fi
export PATH

if [ -z "$LD_LIBRARY_PATH" ]; then
  LD_LIBRARY_PATH=/opt/mnt/Xilinx/Vivado/2017.2/ids_lite/ISE/lib/lin64
else
  LD_LIBRARY_PATH=/opt/mnt/Xilinx/Vivado/2017.2/ids_lite/ISE/lib/lin64:$LD_LIBRARY_PATH
fi
export LD_LIBRARY_PATH

HD_PWD='/home/rewingchow/ECE1373_assignment2-2021_2017.2_InputTest/8v3_shell/test_proj/mig_shell.runs/impl_1'
cd "$HD_PWD"

HD_LOG=runme.log
/bin/touch $HD_LOG

ISEStep="./ISEWrap.sh"
EAStep()
{
     $ISEStep $HD_LOG "$@" >> $HD_LOG 2>&1
     if [ $? -ne 0 ]
     then
         exit
     fi
}

# pre-commands:
/bin/touch .init_design.begin.rst
EAStep vivado -log static_region_wrapper.vdi -applog -m64 -product Vivado -messageDb vivado.pb -mode batch -source static_region_wrapper.tcl -notrace


