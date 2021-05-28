#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>



int main (){
	
	    
        // Read From File & Write to FGPA Memory
        float input_image[7500]={0};
        char line[100];
        int temp;
        FILE * captcha = fopen("input_image.txt", "r");
        int i = 0;

        struct timespec timer;
        timer.tv_sec = 0;
        timer.tv_nsec = 150000000;



        while(!feof(captcha)){
        	fscanf(captcha, "%d", &temp);
        	input_image[i++] = (float)temp;
        }

	    char test_file_name[] = "InputImage.bin";
	    FILE * fp = fopen(test_file_name, "wb");
	    size_t element_size = sizeof(*input_image);
	    size_t number_elements = 7500;

	    fwrite(input_image, element_size, number_elements, fp);
        fclose(captcha);
	    fclose(fp);
	    strcpy(line, "sudo ./write_test.sh");
	    system(line);



            nanosleep (&timer, NULL);
	    

	    // Read From FGPA Memory & Write to File
	    float result_out[5];

	    strcpy(line, "sudo ./read_test.sh");
	    system(line);

	    
	    char output_name[] = "output_result.bin";
	    FILE * result = fopen(output_name, "rb");
	    fread(result_out, element_size, 5, result);
	    fclose(result);


	    

	    FILE * prediction = fopen("prediction.txt", "w");
	    fprintf(prediction, "%c%c%c%c%c\n", (int)result_out[0], (int)result_out[1], (int)result_out[2], (int)result_out[3], (int)result_out[4]);
	    fclose(prediction);
	    
	    return 0;
}
