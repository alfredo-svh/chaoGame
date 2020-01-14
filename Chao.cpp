#include <cstdlib>
#include <ctime>
#include <cmath>
#include <iostream>
#include "Chao.h"



using namespace std;

Chao::Chao(uint8_t egg_color)
{
	srand(time(NULL));

	_name="";
	_garden=NO_GARDEN;
	_happiness=0;
	_rem_lifespan = 3800;
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
	_hunger = 4000;
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

	if(egg_color<=BLACK_MONO){
		_color=_color1=_color2=egg_color;
	}else if(egg_color<=BLACK_TWO){
		_color = _color1 =_color2 = egg_color - BLACK_MONO;
	}else if(egg_color<=BLACK_SHI_MONO){
		_color = _color1 =_color2 = egg_color - NORMAL_SHI;
	}else
		_color = _color1 =_color2 = egg_color - BLACK_SHI_MONO;

}

Chao::Chao(Chao parent1, Chao parent2)
{
	//TODO: understand genetics

}


void Chao::increase_stat(uint8_t stat, int8_t val)
{
	if(val<0){
		val = -val;

		if(_bars[stat] - val <0){
			_bars[stat]=0;
		}
		else{
			_bars[stat] -= val;
		}
	}

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

void Chao::reset() //aka reincarnate()
{
	if(_type %3 ==0){		//hero
		_alignment = 1.0;
	}else if(_type%3==1){	//dark
		_alignment = -1.0;
	}else{					//neutral
		_alignment =0.0;
	}
	_rem_lifespan = 3800;
	_animal_behaviors =0;
	_run_power = 0.0;
	_swim_fly = 0.0;
	_transformation_magnitude = 0.0;

	for(int i=0;i<7;i++){
		_bars[i] = 0;
		_levels[i] = 1;
		_points[i] /= 10;
	}

	_mating =0;

	_type = EGG;
	_reincarnations++;
}

uint8_t Chao::evolve()
{
	if(_swim_fly <= -0.5 && -_swim_fly >= fabs(_run_power)){
		_type = NEU_SWI;
		if(_grades[SWIM]<S){
			_grades[SWIM]++;
			_grades1[SWIM]++;
		}

	}else if(fabs(_run_power) >=0.5 && fabs(_run_power)>= _swim_fly){
		if(_run_power < 0.0){
			_type = NEU_RUN;
			if(_grades[RUN]<S){
				_grades[RUN]++;
				_grades1[RUN]++;
			}
		}
		else{
			_type=NEU_POW;
			if(_grades[POWER]<S){
				_grades[POWER]++;
				_grades1[POWER]++;
			}
		}
	}else if(_swim_fly>=0.5){
		_type = NEU_FLY;
		if(_grades[FLY]<S){
			_grades[FLY]++;
			_grades1[FLY]++;
		}
	}else{
		if(_reincarnations>=2 && _happiness>=80 && (_animal_behaviors & 0b111111111111111) == 0b111111111111111){
			_type = NEU_CHAOS;
			_eyes = GREEN_CHAOS;
			_mouth = 255;
			_emotiball = NORMAL;
			_hidden_feet = false;

			for(int i=0;i<8;i++){
				_bodyparts[i]=0;
			}
		}
		else
			_type = NEU_NOR;

		if(_grades[STAMINA]<S){
			_grades[STAMINA]++;
			_grades1[STAMINA]++;
		}
	}


	//set alignment
	if(_alignment>=0.5){ //hero
		if(_type==NEU_CHAOS)
			_eyes++;
		_type++;
	}
	else if(_alignment<=-0.5){ //dark
		if(_type==NEU_CHAOS)
			_eyes+=2;
		_type+=2;
	}

	//reset sliders
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
		if(_rem_lifespan >= 9979)
			_rem_lifespan = 9999;
		else
			_rem_lifespan+=20;
	}

	switch(fruit){
		case CHAO_GAR_FRT:
			increase_stat(STAMINA, 40);
			if(_type==CHILD){
				_transformation_magnitude+=0.02;
			}else{
				if(_transformation_magnitude >=1.1995)
					_transformation_magnitude = 1.2;
				else
					_transformation_magnitude+=0.005;
			}
			break;
			
        case HERO_GAR_FRT:
            increase_stat(STAMINA, 40);
            if(_type==CHILD){
                _transformation_magnitude+=0.02;
            }else{
				if(_transformation_magnitude >=1.1995)
					_transformation_magnitude = 1.2;
				else
                	_transformation_magnitude+=0.005;
            }   
            break;

        case DARK_GAR_FRT:
            increase_stat(STAMINA, 40);
            if(_type==CHILD){
                _transformation_magnitude+=0.02;
            }else{
				if(_transformation_magnitude >=1.1995)
					_transformation_magnitude = 1.2;
				else
                	_transformation_magnitude+=0.005;
            }   
            break;

        case STRONG_FRT:
            increase_stat(STAMINA, 50);
            if(_type==CHILD){
                _transformation_magnitude+=0.02;
            }else{
				if(_transformation_magnitude >=1.1995)
					_transformation_magnitude = 1.2;
				else
                	_transformation_magnitude+=0.005;
            }   
            break;

        case TASTY_FRT:
            increase_stat(STAMINA, 30);
            increase_stat(INTELLIGENCE, 50);
            increase_stat(LUCK, 50);
            if(_type==CHILD){
                _transformation_magnitude+=0.02;
            }else{
				if(_transformation_magnitude >=1.1988)
					_transformation_magnitude = 1.2;
				else
                	_transformation_magnitude+=0.012;
            }   
            break;

        case HERO_FRT:
            increase_stat(STAMINA, 40);
            if(_type==CHILD){
                _transformation_magnitude+=0.02;
				_alignment+=0.150;
            }else{
				if(_transformation_magnitude >=1.1995)
					_transformation_magnitude = 1.2;
				else
                	_transformation_magnitude+=0.005;
            }   
            break;

        case DARK_FRT:
            increase_stat(STAMINA, 40);
            if(_type==CHILD){
                _transformation_magnitude+=0.02;
				_alignment-=0.150;
            }else{
				if(_transformation_magnitude >=1.1995)
					_transformation_magnitude = 1.2;
				else
                	_transformation_magnitude+=0.005;
            }   
            break;

        case ROUND_FRT:
            increase_stat(STAMINA, 40);
            if(_type==CHILD){
                _transformation_magnitude+=0.02;
            }else{
				if(_transformation_magnitude >=1.1995)
					_transformation_magnitude = 1.2;
				else
                	_transformation_magnitude+=0.005;
            }   
            break;

        case SQUARE_FRT:
            increase_stat(STAMINA, 40);
            if(_type==CHILD){
                _transformation_magnitude+=0.02;
            }else{
				if(_transformation_magnitude >=1.1995)
					_transformation_magnitude = 1.2;
				else
                	_transformation_magnitude+=0.005;
            }   
            break;

        case TRIANGLE_FRT:
            increase_stat(STAMINA, 40);
            if(_type==CHILD){
                _transformation_magnitude+=0.02;
            }else{
				if(_transformation_magnitude >=1.1995)
					_transformation_magnitude = 1.2;
				else
                	_transformation_magnitude+=0.005;
            }   
            break;

        case HEART_FRT:
            increase_stat(STAMINA, 40);
            if(_type==CHILD){
                _transformation_magnitude+=0.02;
            }else{
				if(_transformation_magnitude >=1.1995)
					_transformation_magnitude = 1.2;
				else
                	_transformation_magnitude+=0.005;
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
				if(_transformation_magnitude >=1.1995)
					_transformation_magnitude = 1.2;
				else
                	_transformation_magnitude+=0.005;
            }   
            break;

        case MUSHROOM:
            increase_stat(STAMINA, 80);
            increase_stat(LUCK, 50);
            increase_stat(INTELLIGENCE, 4);
            if(_type==CHILD){
                _transformation_magnitude+=0.02;
            }else{
				if(_transformation_magnitude >=1.1995)
					_transformation_magnitude = 1.2;
				else
                	_transformation_magnitude+=0.005;
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
	//TODO: foreach: increase stats, transformation, behaviors, bodyParts(not CHAOS), EFFECTS!!!
	//TODO: reserch effects: feet bool, emotiball bool

	switch(_animal_behaviors){
		case(PENGUIN):
			_animal_behaviors = _animal_behaviors | F_PENGUIN;
			if(_type< NEU_CHAOS){
				_bodyparts[ARMS] = PENGUIN;
				_bodyparts[FOREHEAD] = PENGUIN;
				_bodyparts[LEGS] = PENGUIN;
			}
			increase_stat(SWIM, 44);
			increase_stat(FLY, -4);
			increase_stat(RUN, 8);
			increase_stat(POWER, -16);

			if(_type==CHILD){
				if(_swim_fly<=-0.9)
					_swim_fly = -1.0;
				else
					_swim_fly-=0.1;
			}else{
				if(_swim_fly<=0.95)
					_swim_fly = -1.0;
				else
					_swim_fly-=0.05;
			}

			break;
	};
	increase_stat(LUCK, 20);
	increase_stat(INTELLIGENCE, 20);
	if(character%2==0){
		if(_alignment>=0.975)
			_alignment = 1.0;
		else
			_alignment+=0.025;
	}else{
		if(_alignment<=-0.975)
			_alignment= -1.0;
		else
			_alignment-=0.025;
	}

}

void Chao::take_drive(uint8_t drive, uint8_t character)
{
	switch(drive){
		case YELLOW_DRIVE:
			increase_stat(SWIM, 24);
			if(_type==CHILD){
				if(_swim_fly<=-0.95)
					_swim_fly = -1.0;
				else
					_swim_fly -=0.05;
			}else{
                if(_swim_fly<=-0.975)
                    _swim_fly = -1.0;
                else
                    _swim_fly -=0.025;
			}
			break;

		case PURPLE_DRIVE:
			increase_stat(FLY, 24);
            if(_type==CHILD){
                if(_swim_fly>=0.95)
                    _swim_fly = 1.0;
                else
                    _swim_fly +=0.05;
            }else{
                if(_swim_fly>=0.975)
                    _swim_fly = 1.0;
                else
                    _swim_fly +=0.025;
            }
            break;

		case GREEN_DRIVE:
			increase_stat(RUN, 24);
            if(_type==CHILD){
                if(_run_power<=-0.95)
                    _run_power = -1.0;
                else
                    _run_power -=0.05;
            }else{
                if(_run_power<=-0.975)
                    _run_power = -1.0;
                else
                    _run_power -=0.025;
            }
            break;

		case RED_DRIVE:
			increase_stat(POWER, 24);
            if(_type==CHILD){
                if(_run_power>=0.95)
                    _run_power = 1.0;
                else
                    _run_power +=0.05;
            }else{
                if(_run_power>=0.975)
                    _run_power = 1.0;
                else
                    _run_power +=0.025;
            }
            break;
	};

	increase_stat(LUCK, 40);
	increase_stat(INTELLIGENCE, 20);
	if(character%2==0){
		_alignment+=0.025;
	}else{
		_alignment-=0.025;
	}

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
