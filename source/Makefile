

# hardware related commands
input_layer: input/* util/*
			vivado_hls ./hls_proj/input_layer.tcl

conv_layer: conv/* util/*
			vivado_hls ./hls_proj/conv_layer_one.tcl & vivado_hls ./hls_proj/conv_layer_two.tcl & vivado_hls ./hls_proj/conv_layer_three.tcl

batch_norm_layer: batch_norm/* util/*
				vivado_hls ./hls_proj/batch_norm_layer_one.tcl & vivado_hls ./hls_proj/batch_norm_layer_two.tcl & vivado_hls ./hls_proj/batch_norm_layer_three.tcl

max_pool_layer: batch_norm/* util/*
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