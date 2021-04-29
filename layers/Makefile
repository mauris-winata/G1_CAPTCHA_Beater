all:
	gcc -Wall -o layer_test */*.c *.c -lm
	
dense_layers:
	./hls_proj/generate_dense_layers

max_pool_dense_layers:
	./hls_proj/generate_max_pool_dense_layers
clean: 
	rm -f layer_test
	rm -f -r ./hls_proj/*.prj
	
