#include<stdio.h>
#include<time.h>


int main(){
	srand(time(NULL));

	int input = 784, hidden = 20, outputIn = 20, outputOut = 10;
	int inputLayer[input][hidden];
	int hiddenLayer[hidden][outputIn];
	int outputLayer[outputIn][outputOut];
	for(int i = 0; i < input; i++)
		for(int j = 0; j < hidden; j++)
			inputLayer[i][j] = (double)rand()/RAND_MAX;
	
	for(int i = 0; i < hidden; i++)
		for(int j = 0; j < ouputIn; j++)
			hiddenLayer[i][j] = (double)rand()/RAND_MAX;
	for(int i = 0; i < outputIn; i++)
		for(int j = 0; j < outputOut; j++)
			
}
