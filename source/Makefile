

# hardware related commands
input_layer: input/* util/*
			vivado_hls ./hls_proj/input_layer.tcl

batch_norm_layer: batch_norm/* util/*
			vivado_hls ./hls_proj/batch_norm_layer_one.tcl & vivado_hls ./hls_proj/batch_norm_layer_two.tcl & vivado_hls ./hls_proj/batch_norm_layer_three.tcl

max_pool_dense_layer: conv/* dense/* util/*
					vivado_hls ./hls_proj/max_pool_dense_layer_one.tcl & vivado_hls ./hls_proj/max_pool_dense_layer_two.tcl & vivado_hls ./hls_proj/max_pool_dense_layer_three.tcl\
& vivado_hls ./hls_proj/max_pool_dense_layer_four.tcl & vivado_hls ./hls_proj/max_pool_dense_layer_five.tcl

dense_layer: conv/* dense/* util/*
			vivado_hls ./hls_proj/dense_layer_one.tcl & vivado_hls ./hls_proj/dense_layer_two.tcl & vivado_hls ./hls_proj/dense_layer_three.tcl\
& vivado_hls ./hls_proj/dense_layer_four.tcl & vivado_hls ./hls_proj/dense_layer_five.tcl