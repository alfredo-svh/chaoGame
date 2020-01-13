#include <cstdlib>
#include <ctime>
#include "Chao.h"



using namespace std;

Chao::Chao(uint8_t egg_color)
{
}

Chao::Chao(Chao parent1, Chao parent2)
{

}


void Chao::increase_stat(uint8_t stat, uint8_t val)
{
	//TODO: handle stats increase for all cases

}

void Chao::heart(uint8_t character)
{
	srand(time(NULL));
	uint8_t chance = rand() %4;

	if(chance==1){
		if(_happiness<100)
			_happiness++;

		if(character%2==0){
			if(_alignment>=0.95)
				_alignment = 1.0;
			else
				_alignment+= 0.05;
		}
		else{
			if(_alignment <= -0.95)
				_alignment = -1.0;
			else
				_alignment -= 0.05;
		}

		if(_bonds[character]<100)
			_bonds[charachter]++;
	}


}

void Chao::reset()
{
	//called by reincarnate

	//TODO: reset what needs to be reset

	_type = CHILD;
	_reincarnations++;
}

uint8_t Chao::evolve()
{
	//TODO: check vlues, set values
	return 0;

}

bool die(Chao* chao)
{
	if(chao->happiness() > 50){
		chao->reset();
		return false;
	}

	else
		delete chao;
		return true;
}

void Chao::name_chao(std::string name)
{
	_name = name;
}

void Chao::eat(uint8_t fruit, uint8_t character)
{
	//TODO foreach fruit: stats, alignment, transformation, magnitude, 
	//TODO remember: full fruit!!!!

	heart(character);

	if(_hunger<=500)
		_hunger=0;
	else
		_hunger-=500;
	
	if(_bonds[character]<100)
		_bonds[character]++;

	if(character%2==0){	//hero
		if(_alignment >= 0.975)
			_alignment = 1.00;
		else
			_alignment+=0.025;
	}else{
		if(_alignment <= -0.975)
			_alignment = -1.00;
		else
			_alignment -= 0.025;
	}

	if(_type==CHILD){
		if(_rem_lifespan1 >= 9987)
			_rem_lifespan1 = 9999;
		else
			_rem_lifespan1+=12;
		if(_rem_lifespan2 >= 9979)
			_rem_lifespan2 = 9999;
		else
			_rem_lifespan2+=20;
	}
}

void Chao::pet(uint8_t character)
{
	heart(character);
}

void Chao::pickup(uint8_t character)
{
	//TODO: display info
	heart(character);

}

void Chao::thrown(uint8_t character)
{
	if(_happiness<=-95)
        _happiness = -100;
    else
        _happiness-=5;

    if(character%2==0){  //hero
		if(_alignment<=-0.95)
			_alignment=-1.00;
		else
        	_alignment-=0.05;
	}else{
		if(_alignment >=0.95)
			_alignment = 1.00;
		else
        	_alignment+=0.05;
	}

    if(_bonds[character] <= -95)
        _bonds[character] = -100;
    else
        _bonds[character]-=5;
	
}

void Chao::abuse(uint8_t character)
{
	if(_happiness<=-70)
		_happiness = -100;
	else
		_happiness-=30;

	if(character%2==0){	//hero
		if(_alignment<=-0.95)
			_alignment = -1.00;
		else
			_alignment-=0.05;
	}else{
		if(_alignment>=0.95)
			_alignment = 1.00;
		else
			_alignment+=0.05;
	}

	if(_bonds[character] <= -70)
		_bonds[character] = -100;
	else
		_bonds[character]-=30;
}

void Chao::take_animal(uint8_t animal, uint8_t character)
{
	//TODO: foreach animal: increase stats, transformation, behaviors, bodyParts
	increase_stat(LUCK, 20);
	increase_stat(INTELLIGENCE, 20);
	heart(character);

}

void Chao::take_drive(uint8_t drive, uint8_t character)
{
	switch(drive){
		case YELLOW_DRIVE:
			increase_stat(SWIM, 24);
			if(_swim_fly>=-0.95){
				if(_type==CHILD){
					_swim_fly-=0.05;
				}else{
					_swim_fly-=0.025;
				}
			}
			break;

		case PURPLE_DRIVE:
			increase_stat(FLY, 24);
			if(_swim_fly<=0.95){
            	if(_type==CHILD){
                	_swim_fly+=0.05;
            	}else{
                	_swim_fly+=0.025;
            	}
			}
            break;

		case GREEN_DRIVE:
			increase_stat(RUN, 24);
			if(_run_power >=-0.95){
            	if(_type==CHILD){
                	_run_power-=0.05;
            	}else{
                	_run_power-=0.025;
            	}
			}
            break;

		case RED_DRIVE:
			increase_stat(POWER, 24);
			if(_run_power<=0.95){
            	if(_type==CHILD){
                	_run_power+=0.05;
            	}else{
                	_run_power+=0.025;
            	}
			}
            break;
	};

	increase_stat(LUCK, 40);
	increase_stat(INTELLIGENCE, 20);
	heart(character);

}

void Chao::take_hat(uint8_t hat)
{
	if((_animal_behaviors & F_SKELETONDOG) == F_SKELETONDOG)
		_hat = hat;

}

void Chao::win(uint8_t medal_prize, uint8_t toy_prize=0)
{
	_toys = _toys | toy_prize;
	_medal = medal_prize;

}

void Chao::learn(uint8_t lesson)
{
	_classroom_skills = _classroom_skills | lesson;

}

void Chao::medicine(uint8_t sickness)
{
	switch(sickness){
		case 1:
			_cough = 100;
			break;
		case 2:
			_cold = 100;
			break;
		case 3:
			_rash = 100;
			break;
		case 4:
			_runny_nose = 100;
			break;
		case 5:
			_hiccups = 100;
			break;
		case 6:
			_stomach_ache = 100;
			break;
	};

}
