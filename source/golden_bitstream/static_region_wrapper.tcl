proc start_step { step } {
  set stopFile ".stop.rst"
  if {[file isfile .stop.rst]} {
    puts ""
    puts "*** Halting run - EA reset detected ***"
    puts ""
    puts ""
    return -code error
  }
  set beginFile ".$step.begin.rst"
  set platform "$::tcl_platform(platform)"
  set user "$::tcl_platform(user)"
  set pid [pid]
  set host ""
  if { [string equal $platform unix] } {
    if { [info exist ::env(HOSTNAME)] } {
      set host $::env(HOSTNAME)
    }
  } else {
    if { [info exist ::env(COMPUTERNAME)] } {
      set host $::env(COMPUTERNAME)
    }
  }
  set ch [open $beginFile w]
  puts $ch "<?xml version=\"1.0\"?>"
  puts $ch "<ProcessHandle Version=\"1\" Minor=\"0\">"
  puts $ch "    <Process Command=\".planAhead.\" Owner=\"$user\" Host=\"$host\" Pid=\"$pid\">"
  puts $ch "    </Process>"
  puts $ch "</ProcessHandle>"
  close $ch
}

proc end_step { step } {
  set endFile ".$step.end.rst"
  set ch [open $endFile w]
  close $ch
}

proc step_failed { step } {
  set endFile ".$step.error.rst"
  set ch [open $endFile w]
  close $ch
}

set_msg_config  -ruleid {5}  -id {[BD 41-1306]}  -suppress 
set_msg_config  -ruleid {6}  -id {[BD 41-1271]}  -suppress 

start_step init_design
set ACTIVE_STEP init_design
set rc [catch {
  create_msg_db init_design.pb
  create_project -in_memory -part xcvu095-ffvc1517-2-e
  set_property design_mode GateLvl [current_fileset]
  set_param project.singleFileAddWarning.threshold 0
  set_property webtalk.parent_dir /home/rewingchow/ECE1373_assignment2-2021_2017.2_InputTest/8v3_shell/test_proj/mig_shell.cache/wt [current_project]
  set_property parent.project_path /home/rewingchow/ECE1373_assignment2-2021_2017.2_InputTest/8v3_shell/test_proj/mig_shell.xpr [current_project]
  set_property ip_repo_paths {
  /home/rewingchow/ECE1373_assignment2-2021_2017.2_InputTest/8v3_shell/ocl_ips
  /home/rewingchow/ECE1373_Final_Project-fixed_point
  /home/rewingchow/COSIM
  /home/rewingchow/mp2_IP
  /home/rewingchow/mp3_IP
  /home/rewingchow/Optimized_MP1
} [current_project]
  set_property ip_output_repo /home/rewingchow/ECE1373_assignment2-2021_2017.2_InputTest/8v3_shell/test_proj/mig_shell.cache/ip [current_project]
  set_property ip_cache_permissions {read write} [current_project]
  set_property XPM_LIBRARIES {XPM_CDC XPM_FIFO XPM_MEMORY} [current_project]
  add_files -quiet /home/rewingchow/ECE1373_assignment2-2021_2017.2_InputTest/8v3_shell/test_proj/mig_shell.runs/synth_1/static_region_wrapper.dcp
  set_msg_config -source 4 -id {BD 41-1661} -suppress
  set_param project.isImplRun true
  add_files /home/rewingchow/ECE1373_assignment2-2021_2017.2_InputTest/8v3_shell/test_proj/mig_shell.srcs/sources_1/bd/static_region/static_region.bd
  set_property is_locked true [get_files /home/rewingchow/ECE1373_assignment2-2021_2017.2_InputTest/8v3_shell/test_proj/mig_shell.srcs/sources_1/bd/static_region/static_region.bd]
  set_param project.isImplRun false
  read_xdc /home/rewingchow/ECE1373_assignment2-2021_2017.2_InputTest/8v3_shell/test_proj/mig_shell.srcs/constrs_1/imports/8v3_shell/bitstream.xdc
  read_xdc /home/rewingchow/ECE1373_assignment2-2021_2017.2_InputTest/8v3_shell/test_proj/mig_shell.srcs/constrs_1/imports/8v3_shell/ddr4sdram_b0_lane8.xdc
  read_xdc /home/rewingchow/ECE1373_assignment2-2021_2017.2_InputTest/8v3_shell/test_proj/mig_shell.srcs/constrs_1/imports/8v3_shell/ddr4sdram_b0_unused.xdc
  read_xdc /home/rewingchow/ECE1373_assignment2-2021_2017.2_InputTest/8v3_shell/test_proj/mig_shell.srcs/constrs_1/imports/8v3_shell/ddr4sdram_locs_b0_twin_die.xdc
  read_xdc /home/rewingchow/ECE1373_assignment2-2021_2017.2_InputTest/8v3_shell/test_proj/mig_shell.srcs/constrs_1/imports/8v3_shell/ddr4sdram_locs_b0_x64.xdc
  read_xdc /home/rewingchow/ECE1373_assignment2-2021_2017.2_InputTest/8v3_shell/test_proj/mig_shell.srcs/constrs_1/imports/8v3_shell/ddr4sdram_locs_b0_x72.xdc
  read_xdc /home/rewingchow/ECE1373_assignment2-2021_2017.2_InputTest/8v3_shell/test_proj/mig_shell.srcs/constrs_1/imports/8v3_shell/ddr4sdram_props_b0_twin_die.xdc
  read_xdc /home/rewingchow/ECE1373_assignment2-2021_2017.2_InputTest/8v3_shell/test_proj/mig_shell.srcs/constrs_1/imports/8v3_shell/pcie_constr.xdc
  set_param project.isImplRun true
  link_design -top static_region_wrapper -part xcvu095-ffvc1517-2-e
  set_param project.isImplRun false
  write_hwdef -force -file static_region_wrapper.hwdef
  close_msg_db -file init_design.pb
} RESULT]
if {$rc} {
  step_failed init_design
  return -code error $RESULT
} else {
  end_step init_design
  unset ACTIVE_STEP 
}

start_step opt_design
set ACTIVE_STEP opt_design
set rc [catch {
  create_msg_db opt_design.pb
  opt_design 
  write_checkpoint -force static_region_wrapper_opt.dcp
  catch { report_drc -file static_region_wrapper_drc_opted.rpt }
  close_msg_db -file opt_design.pb
} RESULT]
if {$rc} {
  step_failed opt_design
  return -code error $RESULT
} else {
  end_step opt_design
  unset ACTIVE_STEP 
}

start_step place_design
set ACTIVE_STEP place_design
set rc [catch {
  create_msg_db place_design.pb
  implement_debug_core 
  place_design 
  write_checkpoint -force static_region_wrapper_placed.dcp
  catch { report_io -file static_region_wrapper_io_placed.rpt }
  catch { report_utilization -file static_region_wrapper_utilization_placed.rpt -pb static_region_wrapper_utilization_placed.pb }
  catch { report_control_sets -verbose -file static_region_wrapper_control_sets_placed.rpt }
  close_msg_db -file place_design.pb
} RESULT]
if {$rc} {
  step_failed place_design
  return -code error $RESULT
} else {
  end_step place_design
  unset ACTIVE_STEP 
}

start_step route_design
set ACTIVE_STEP route_design
set rc [catch {
  create_msg_db route_design.pb
  route_design 
  write_checkpoint -force static_region_wrapper_routed.dcp
  catch { report_drc -file static_region_wrapper_drc_routed.rpt -pb static_region_wrapper_drc_routed.pb -rpx static_region_wrapper_drc_routed.rpx }
  catch { report_methodology -file static_region_wrapper_methodology_drc_routed.rpt -rpx static_region_wrapper_methodology_drc_routed.rpx }
  catch { report_power -file static_region_wrapper_power_routed.rpt -pb static_region_wrapper_power_summary_routed.pb -rpx static_region_wrapper_power_routed.rpx }
  catch { report_route_status -file static_region_wrapper_route_status.rpt -pb static_region_wrapper_route_status.pb }
  catch { report_clock_utilization -file static_region_wrapper_clock_utilization_routed.rpt }
  catch { report_timing_summary -warn_on_violation -max_paths 10 -file static_region_wrapper_timing_summary_routed.rpt -rpx static_region_wrapper_timing_summary_routed.rpx }
  close_msg_db -file route_design.pb
} RESULT]
if {$rc} {
  write_checkpoint -force static_region_wrapper_routed_error.dcp
  step_failed route_design
  return -code error $RESULT
} else {
  end_step route_design
  unset ACTIVE_STEP 
}

start_step write_bitstream
set ACTIVE_STEP write_bitstream
set rc [catch {
  create_msg_db write_bitstream.pb
  set_property XPM_LIBRARIES {XPM_CDC XPM_FIFO XPM_MEMORY} [current_project]
  catch { write_mem_info -force static_region_wrapper.mmi }
  write_bitstream -force static_region_wrapper.bit 
  catch { write_sysdef -hwdef static_region_wrapper.hwdef -bitfile static_region_wrapper.bit -meminfo static_region_wrapper.mmi -file static_region_wrapper.sysdef }
  catch {write_debug_probes -no_partial_ltxfile -quiet -force debug_nets}
  catch {file copy -force debug_nets.ltx static_region_wrapper.ltx}
  close_msg_db -file write_bitstream.pb
} RESULT]
if {$rc} {
  step_failed write_bitstream
  return -code error $RESULT
} else {
  end_step write_bitstream
  unset ACTIVE_STEP 
}

