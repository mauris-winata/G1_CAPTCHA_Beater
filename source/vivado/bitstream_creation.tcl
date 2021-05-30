synth_design -top static_region_wrapper -mode out_of_context
opt_design -directive Explore
place_design -directive Explore
phys_opt_design -directive Explore
route_design -directive Explore
write_bitstream -force ../captcha_beater.bit 

