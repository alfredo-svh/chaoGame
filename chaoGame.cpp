#include "Chao.h"
#include <cstdlib>
#include <iostream>
#include <ctime>
#include <thread>
#include <chrono>

using namespace std;

int main(){
	uint16_t input;
	uint16_t egg_color;
	uint16_t character;
	uint8_t garden=NO_GARDEN;
	string name;
	srand(time(NULL));

	cout <<endl<< "\t\t\tWELCOME TO CHAO WORLD!"<<endl;
	cout << "This game is based on the chaos from Sonic Adventure 2: Battle"<<endl<<endl;
	this_thread::sleep_for(chrono::seconds(1));
	cout << "Choose your character:"<<endl;
	cout << "0-Sonic, 1-Shadow, 2-Tails,3-Eggman, 4-Knuckles, 5-Rouge"<<endl;
	cin>>character;

	cin>>input;

	if(input ==1){
		egg_color = rand() % 54;
		Chao chao1(egg_color);

		garden=CHAO_GARDEN;
		cout << "You got a " << egg_color << "-colored egg! Wait for it to hatch."<<endl;
		this_thread::sleep_for(chrono::seconds(3));
		chao1.born(garden);
		cout << "The egg hatched! Your new chao is born!"<<endl;

		while(1){
			cout<< "What do you wanna do next?"<<endl;
			cin>> input;

			switch(input){
				case 1:
					cout<<"Name your Chao!"<<endl;
					cin >> name;
					chao1.name_chao(name);
					cout <<endl <<"Your chao has been named "<<name<<"!"<<endl<<endl;
					break;

				case 2:
					cout<<"Welcome to the health center!"<<endl<<endl;
					chao1.doctor();
					break;

				case 3:
					chao1.pet(character);
					cout<<"Your chao enjoyed your petting"<<endl<<endl;
					break;

				case 4:
					cout<<"Welcome to Chao karate. Select your level (1-4)"<<endl;
					cin >> input;
					input--;
					if(input<4)
						chao1.karate(input);

				default:
					cout << "Goodbye! Changes will not be saved"<<endl;
					return 0;
			};
		}
	}

	cout << "Goodbye! Changes will not be saved"<<endl;

	return 0;

}
