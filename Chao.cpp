#include <cstdlib>
#include <ctime>
#include <iostream>
#include "Chao.h"



using namespace std;

Chao::Chao(uint8_t egg_color)
{
	srand(time(NULL));

	_name="";
	_garden=NO_GARDEN;
	_happiness=0;
	_reset = 1;
	_rem_lifespan1 = 3800;
	_rem_lifespan2 = 3800;
	_reincarnations = 0;
	_animal_behaviors = F_NOAN;
	_classroom_skills = NO_ABIL;
	_toys = NO_TOY;

	_type = EGG;
	_alignment = 0.0;
	_run_power = 0.0;
	_swim_fly = 0.0;
	_transformation_magnitude = 0;

	for(int i=0;i<7;i++){
		_bars[i] = 0;
		_grades[i] = rand() % 6;
		_grades1[i] = _grades[i];
		_grades2[i] = _grades[i];
		_levels[i] = 0;
		_points[i] = 0;
	}
	_grades[LUCK] = rand() % 256;
	_grades1[LUCK] = _grades[LUCK];
	_grades2[LUCK] = _grades[LUCK];
	_grades[INTELLIGENCE] = rand() % 256;
	_grades1[INTELLIGENCE] = _grades[INTELLIGENCE];
	_grades2[INTELLIGENCE] = _grades[INTELLIGENCE];

	if((egg_color >=YELLOW_MONO && egg_color <= BLACK_MONO) || (egg_color >= YELLOW_SHI_MONO && egg_color <= BLACK_SHI_MONO))
		_monotone=true;
	else
		_monotone = false;

	_monotone1=_monotone2=_monotone;

	_texture=NOTEXT;
	_texture1=_texture2 = _texture;

	if(egg_color >= NORMAL_SHI && egg_color <= BLACK_SHI_TWO)
		_shiny = true;
	else
		_shiny=false;
	_shiny1=_shiny2=_shiny;

	_egg_color=egg_color;
	_egg_color1= _egg_color2=_egg_color;
	_medal = NOMEDAL;
	_hat = NOHAT;
	_eyes = rand()%11;
	_mouth = rand()%16;
	_emotiball = NORMAL;
	_hidden_feet = false;

	for(int i=0;i<8;i++){
		_bodyparts[i] = NOAN;
	}

	for(int i=0;i<6;i++){
		_bonds[i]=0;
	}

	_mating = 0;
	_hunger = 2000;
	_sleepiness = 0;
	_tiredness = 0;
	_boredom = 1000;
	_energy = 3000;

	_joy = 40;
	_cry = 40;
	_fear = 40;
	_dizziness = 0;

	_cough = 100;
	_cold = 100;
	_rash = 100;
	_runny_nose = 100;
	_hiccups = 100;
	_stomach_ache = 100;

	_fav_fruit = rand() % 8;
	_fav_fruit1 = _fav_fruit2 = _fav_fruit;

	_normal_curious = (rand() %201) - 100;
	_kindness = (rand() %201) - 100;
	_crybaby_energetic = (rand() %201) - 100;
	_naive_normal = (rand() %201) - 100;
	_sollitude = (rand() %201) - 100;
	_vitality = (rand() %201) - 100;
	_normal_bigeater = (rand() %201) - 100;
	_regain = (rand() %201) - 100;
	_skillful = (rand() %201) - 100;
	_charm = (rand() %201) - 100;
	_chatty = (rand() %201) - 100;
	_normal_carefree = (rand() %201) - 100;
	_fickle = (rand() %201) - 100;


	switch(egg_color){
		case NORMAL_EGG:
		case NORMAL_SHI:
			_color = _color1 = _color2 = NORMAL_COLOR;
			break;
		case YELLOW_MONO:
		case YELLOW_TWO:
		case YELLOW_SHI_MONO:
		case YELLOW_SHI_TWO:
			_color = _color1 = _color2 = YELLOW;
			break;
        case WHITE_MONO:
        case WHITE_TWO:
        case WHITE_SHI_MONO:
        case WHITE_SHI_TWO:
            _color = _color1 = _color2 = WHITE;
            break;
        case BROWN_MONO:
        case BROWN_TWO:
        case BROWN_SHI_MONO:
        case BROWN_SHI_TWO:
            _color = _color1 = _color2 = BROWN;
            break;
        case SKY_BLUE_MONO:
        case SKY_BLUE_TWO:
        case SKY_BLUE_SHI_MONO:
        case SKY_BLUE_SHI_TWO:
            _color = _color1 = _color2 = SKY_BLUE;
            break;
        case PINK_MONO:
        case PINK_TWO:
        case PINK_SHI_MONO:
        case PINK_SHI_TWO:
            _color = _color1 = _color2 = PINK;
            break;
        case BLUE_MONO:
        case BLUE_TWO:
        case BLUE_SHI_MONO:
        case BLUE_SHI_TWO:
            _color = _color1 = _color2 = BLUE;
            break;
        case GREY_MONO:
        case GREY_TWO:
        case GREY_SHI_MONO:
        case GREY_SHI_TWO:
            _color = _color1 = _color2 = GREY;
            break;
        case GREEN_MONO:
        case GREEN_TWO:
        case GREEN_SHI_MONO:
        case GREEN_SHI_TWO:
            _color = _color1 = _color2 = GREEN;
            break;
        case RED_MONO:
        case RED_TWO:
        case RED_SHI_MONO:
        case RED_SHI_TWO:
            _color = _color1 = _color2 = RED;
            break;
        case LIME_GREEN_MONO:
        case LIME_GREEN_TWO:
        case LIME_GREEN_SHI_MONO:
        case LIME_GREEN_SHI_TWO:
            _color = _color1 = _color2 = LIME_GREEN;
            break;
        case PURPLE_MONO:
        case PURPLE_TWO:
        case PURPLE_SHI_MONO:
        case PURPLE_SHI_TWO:
            _color = _color1 = _color2 = PURPLE;
            break;
        case ORANGE_MONO:
        case ORANGE_TWO:
        case ORANGE_SHI_MONO:
        case ORANGE_SHI_TWO:
            _color = _color1 = _color2 = ORANGE;
            break;
        case BLACK_MONO:
        case BLACK_TWO:
        case BLACK_SHI_MONO:
        case BLACK_SHI_TWO:
            _color = _color1 = _color2 = BLACK;
            break;

	};

}

Chao::Chao(Chao parent1, Chao parent2)
{
	//TODO: understand genetics

}


void Chao::increase_stat(uint8_t stat, uint8_t val)
{
	if(_bars[stat] + val <=99)
		_bars[stat] += val;
	
	else if(_levels[stat]<99){	//level up
		srand(time(NULL));
		int8_t r = (rand()%5) - 2;

		_bars[stat] = (val+_bars[stat])%100;
		_levels[stat]++;
		_points[stat]+= (_grades[stat]*3) + 13 + r;


	}
	else{
		_bars[stat]=99;
	}
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
			_bonds[character]++;
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

	//TODO: check for && set values for Chaos chao, increase stamina
	//TODO: check vlues, set type, increase rank


	//set alignment
	if(_alignment>=0.5){ //hero
		_type++;
	}
	else if(_alignment<=-0.5){ //dark
		_type+=2;
	}

	//reset alignment, transformations
	_alignment = 0;
	_run_power =0;
	_swim_fly = 0;
	_transformation_magnitude = 0;


	return _type;

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
	//TODO fix overflowing increases/decreases



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

	switch(fruit){
		case CHAO_GAR_FRT:
			increase_stat(STAMINA, 40);
			if(_type==CHILD){
				_transformation_magnitude+=0.02;
			}else{
				_transformation_magnitude+=0.004;
			}
			break;
			
        case HERO_GAR_FRT:
            increase_stat(STAMINA, 40);
            if(_type==CHILD){
                _transformation_magnitude+=0.02;
            }else{
                _transformation_magnitude+=0.004;
            }   
            break;

        case DARK_GAR_FRT:
            increase_stat(STAMINA, 40);
            if(_type==CHILD){
                _transformation_magnitude+=0.02;
            }else{
                _transformation_magnitude+=0.004;
            }   
            break;

        case STRONG_FRT:
            increase_stat(STAMINA, 50);
            if(_type==CHILD){
                _transformation_magnitude+=0.02;
            }else{
                _transformation_magnitude+=0.004;
            }   
            break;

        case TASTY_FRT:
            increase_stat(STAMINA, 30);
            increase_stat(INTELLIGENCE, 50);
            increase_stat(LUCK, 50);
            if(_type==CHILD){
                _transformation_magnitude+=0.02;
            }else{
                _transformation_magnitude+=0.012;
            }   
            break;

        case HERO_FRT:
            increase_stat(STAMINA, 40);
            if(_type==CHILD){
                _transformation_magnitude+=0.02;
				_alignment+=0.150;
            }else{
                _transformation_magnitude+=0.004;
            }   
            break;

        case DARK_FRT:
            increase_stat(STAMINA, 40);
            if(_type==CHILD){
                _transformation_magnitude+=0.02;
				_alignment-=0.150;
            }else{
                _transformation_magnitude+=0.004;
            }   
            break;

        case ROUND_FRT:
            increase_stat(STAMINA, 40);
            if(_type==CHILD){
                _transformation_magnitude+=0.02;
            }else{
                _transformation_magnitude+=0.004;
            }   
            break;

        case SQUARE_FRT:
            increase_stat(STAMINA, 40);
            if(_type==CHILD){
                _transformation_magnitude+=0.02;
            }else{
                _transformation_magnitude+=0.004;
            }   
            break;

        case TRIANGLE_FRT:
            increase_stat(STAMINA, 40);
            if(_type==CHILD){
                _transformation_magnitude+=0.02;
            }else{
                _transformation_magnitude+=0.004;
            }   
            break;

        case HEART_FRT:
            increase_stat(STAMINA, 40);
            if(_type==CHILD){
                _transformation_magnitude+=0.02;
            }else{
                _transformation_magnitude+=0.004;
				_mating = 10000;
            }   
            break;

        case CHAO_FRT:
            increase_stat(STAMINA, 40);
            increase_stat(SWIM, 40);
            increase_stat(FLY, 40);
            increase_stat(RUN, 40);
            increase_stat(POWER, 40);
            if(_type==CHILD){
                _transformation_magnitude+=0.02;
            }else{
                _transformation_magnitude+=0.004;
            }   
            break;

        case MUSHROOM:
            increase_stat(STAMINA, 80);
            increase_stat(LUCK, 50);
            increase_stat(INTELLIGENCE, 4);
            if(_type==CHILD){
                _transformation_magnitude+=0.02;
            }else{
                _transformation_magnitude+=0.004;
            }   
            break;
	};
}

void Chao::pet(uint8_t character)
{
	heart(character);
}

void Chao::pickup(uint8_t character)
{
	cout << _name<<endl<<endl;
	cout << "Swim: " << _points[SWIM] << " Lv. "<< _levels[SWIM]<<endl;
	cout << "Fly: " << _points[FLY] << " Lv. "<< _levels[FLY]<<endl;
	cout << "Run: " << _points[RUN] << " Lv. "<< _levels[RUN]<<endl;
	cout << "Power: " << _points[POWER] << " Lv. "<< _levels[POWER]<<endl;
	cout << "Stamina: " << _points[STAMINA] << " Lv. "<< _levels[STAMINA]<<endl;

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
		if(_alignment<=-0.9)
			_alignment = -1.00;
		else
			_alignment-=0.1;
	}else{
		if(_alignment>=0.9)
			_alignment = 1.00;
		else
			_alignment+=0.1;
	}

	if(_bonds[character] <= -70)
		_bonds[character] = -100;
	else
		_bonds[character]-=30;
}

void Chao::take_animal(uint8_t animal, uint8_t character)
{
	//TODO: fix overflowing increase/decrease
	//TODO: foreach animal: increase stats, transformation, behaviors, bodyParts, effects
	//TODO: research bodyparts, stats

	switch(_animal_behaviors){
		case(PENGUIN):
			_animal_behaviors = _animal_behaviors | F_PENGUIN;

			if(_type==CHILD){
				_swim_fly-=0.1;
			}else{
				_swim_fly-=0.05;
			}

			break;
	};
	increase_stat(LUCK, 20);
	increase_stat(INTELLIGENCE, 20);
	//TODO move alignment by 0.025

}

void Chao::take_drive(uint8_t drive, uint8_t character)
{
	//TODO fix overflow
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
	//TODO: move alignment by 0.025

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
