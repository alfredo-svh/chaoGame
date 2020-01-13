#include "Chao.h"
#include <cstdlib>
#include <iostream>
#include <ctime>
#include <thread>
#include <chrono>

using namespace std;

int main(){
	int input;
	int egg_color;
	int character;
	srand(time(NULL));

	cout << "WELCOME TO CHAO WORLD"<<endl;
	cout << "this game is based on the chaos from Sonic Adventure 2: Battle"<<endl;
	this_thread::sleep_for(chrono::seconds(1));
	cout << "Choose your character:"<<endl;
	cout << "0-Sonic, 1-Shadow, 2-Tails,3-Eggman, 4-Knuckles, 5-Rouge"<<endl;
	cin>>character;
	cout << "Welcome, " <<character << ". Press 1 to get a chao egg."<<endl;

	cin>>input;

	if(input ==1){
		egg_color = rand() % 54;
		Chao one(egg_color);

		cout << "You got a " << egg_color << "-colored egg! Wait for it to hatch."<<endl;
		this_thread::sleep_for(chrono::seconds(3));
		cout << "The egg hatched! Your new chao is born!"<<endl;

		while(1){
			cout<< "What do you wanna do next?"<<endl;
			cin>> input;

			switch(input){
				default:
					cout << "Goodbye! Changes will not be saved"<<endl;
					return 0;
			};
		}
	}

	cout << "Goodbye! Changes will not be saved"<<endl;

	return 0;

}
