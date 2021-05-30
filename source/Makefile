

# hardware related commands
input_layer: input/* util/*
			vivado_hls ./hls_proj/input_layer.tcl

conv_layer: conv/* util/*
			vivado_hls ./hls_proj/conv_layer_one.tcl & vivado_hls ./hls_proj/conv_layer_two.tcl & vivado_hls ./hls_proj/conv_layer_three.tcl

batch_norm_layer: batch_norm/* util/*
				vivado_hls ./hls_proj/batch_norm_layer_one.tcl & vivado_hls ./hls_proj/batch_norm_layer_two.tcl & vivado_hls ./hls_proj/batch_norm_layer_three.tcl

max_pool_layer: max_pool/* util/*
				vivado_hls ./hls_proj/max_pool_layer_one.tcl & vivado_hls ./hls_proj/max_pool_layer_two.tcl & vivado_hls ./hls_proj/max_pool_layer_three.tcl

max_pool_dense_layer: conv/* dense/* util/*
					vivado_hls ./hls_proj/max_pool_dense_layer_one.tcl & vivado_hls ./hls_proj/max_pool_dense_layer_two.tcl & vivado_hls ./hls_proj/max_pool_dense_layer_three.tcl\
& vivado_hls ./hls_proj/max_pool_dense_layer_four.tcl & vivado_hls ./hls_proj/max_pool_dense_layer_five.tcl

dense_layer: conv/* dense/* util/*
			vivado_hls ./hls_proj/dense_layer_one.tcl & vivado_hls ./hls_proj/dense_layer_two.tcl & vivado_hls ./hls_proj/dense_layer_three.tcl\
& vivado_hls ./hls_proj/dense_layer_four.tcl & vivado_hls ./hls_proj/dense_layer_five.tcl

output_layer: output/* util/*
			vivado_hls ./hls_proj/output_layer.tcl

output_memory_layer: output_mem/* util/*
					vivado_hls ./hls_proj/output_memory_layer.tcl

generate_captcha_beater: input_layer conv_layer batch_norm_layer max_pool_layer max_pool_dense_layer dense_layer output_layer output_memory_layer
						cd ./vivado/ && unzip -q mig_shell.xpr.zip && cd ./mig_shell/ && vivado mig_shell.xpr

# software related commands
captcha_beater_software: 
						gcc -o ./util/tests/captchabeater ./util/tests/CaptchaBeater.c

# driver related commands
xdma: 
	cd ./util/xdma/ && make install

xdma_tools:
			cd ./util/tools/ && make

load_driver:
			./util/tests/load_driver.sh