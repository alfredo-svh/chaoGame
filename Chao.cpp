#include <cstdlib>
#include <ctime>
#include <cmath>
#include <iostream>
#include <vector>
#include "Chao.h"

using namespace std;

extern uint16_t garden;
extern uint16_t character;
   

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

	_emotions[MATING] = 0;
	_emotions[HUNGER] = 4000;
	_emotions[SLEEPINESS] = 0;
	_emotions[TIREDNESS] = 0;
	_emotions[BOREDOM] = 1000;
	_emotions[ENERGY] = 3000;


	_behaviors[JOY] = 40;
	_behaviors[CRY] = 40;
	_behaviors[FEAR] = 40;
	_behaviors[DIZZINESS] = 0;

	for(int i=0;i<6;i++)
		_health[i]=100;

	_karate_lvl=_wins=_losses=_draws=0;
	for(int i=0;i<DARK_MEDAL;i++){
		_medals[i]=false;
	}


	_fav_fruit = rand() % 8;
	_fav_fruit1 = _fav_fruit2 = _fav_fruit;

	for(int i=0;i<5;i++)
		_personality[i] = (rand() %201) - 100;

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
	// allele1 = random(parent1.allele1, parent1.allele2)
	//allele2 = random(parent2.allele1, parent2.allele2)
	//fenotype = dominantvsrecessive(allel1, allele2)
	
	//normal color recessive!!
	//shiny dominant allele
	//no_texture is recessive, all other textures: dominant

}

void Chao::move_alignment(float value)
{
	//TODO replace in code
	if(value>0){
		if(_alignment + value>=1.0)
			_alignment=1.0;
		else
			_alignment+=value;
	}else{
		if(_alignment + value<=-1.0)
			_alignment = -1.0;
		else
			_alignment+=value;
	}
}


void Chao::move_transformation(uint8_t stat, float value){
	//TODO replace code w/function where necessary
	//		note: ONLY ABS VALUE!!!!!!
	if(_type!=CHILD)
		value/=2;

	if(stat==RANDOM){
		srand(time(NULL));
		stat = rand()%4;
	}
	switch(stat){
		case SWIM:
			if(_swim_fly - value<=-1.0)
				_swim_fly=-1.0;
			else 
				_swim_fly-=value;
			break;

		case FLY:
			if(_swim_fly + value>=1.0)
				_swim_fly=1.0;
			else 
				_swim_fly+=value;
			break;

		case RUN:
			if(_run_power - value<=-1.0)
				_run_power=-1.0;
			else 
				_run_power-=value;
			break;

		case POWER:
			if(_run_power + value>=1.0)
				_run_power=1.0;
			else 
				_run_power+=value;
			break;
	};
}


void Chao::remove_animalpart(){
	srand(time(NULL));
	_bodyparts[rand()%9] = NOAN;

	if(rand()%2==0)
		_hidden_feet=false;
	else
		_emotiball = NORMAL;
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
		if((stat==LUCK || stat==INTELLIGENCE) && _points[stat]+(_grades[stat]*3) + 13 + r >=4000)
			_points[stat] = 4000;
		else
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
		cout<<"<3"<<endl;
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

	_emotions[MATING] =0;

	_type = EGG;
	_reincarnations++;
}

void Chao::born(uint8_t garden)
{
	_type = CHILD;
	_garden = garden;
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
				_bodyparts[i]=NOAN;
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

	if(_emotions[HUNGER]<=500)
		_emotions[HUNGER]=0;
	else
		_emotions[HUNGER]-=500;
	
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
				_emotions[MATING] = 10000;
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

void Chao::drop(uint8_t garden){
	_garden = garden;
}

void Chao::thrown(uint8_t character, uint8_t garden)
{
	drop(garden);

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
	switch(_animal_behaviors){
		case(PENGUIN):
			_animal_behaviors = _animal_behaviors | F_PENGUIN;
			if(_type< NEU_CHAOS){
				_bodyparts[ARMS] = PENGUIN;
				_bodyparts[FOREHEAD] = PENGUIN;
				_bodyparts[LEGS] = PENGUIN;
			}
			increase_stat(SWIM, 36);
			increase_stat(FLY, 12);
			increase_stat(RUN, 8);
			increase_stat(POWER, -24);

			if(_type==CHILD){
				if(_swim_fly<=-0.9)
					_swim_fly = -1.0;
				else
					_swim_fly-=0.1;
			}else{
				if(_swim_fly<=-0.95)
					_swim_fly = -1.0;
				else
					_swim_fly-=0.05;
			}

			break;
			
		case(SEAL):
			_animal_behaviors = _animal_behaviors | F_SEAL;
			if(_type< NEU_CHAOS){
				_bodyparts[ARMS] = SEAL;
				_bodyparts[TAIL] = SEAL;
			}
			increase_stat(SWIM, 40);
			increase_stat(FLY, -16);
			increase_stat(POWER, 8);

			if(_type==CHILD){
				if(_swim_fly<=-0.9)
					_swim_fly = -1.0;
				else
					_swim_fly-=0.1;
			}else{
				if(_swim_fly<=-0.95)
					_swim_fly = -1.0;
				else
					_swim_fly-=0.05;
			}

			break;
			
		case(OTTER):
			_animal_behaviors = _animal_behaviors | F_OTTER;
			if(_type< NEU_CHAOS){
				_bodyparts[ARMS] = OTTER;
				if(_bodyparts[HORNS]==NOAN)
					_bodyparts[EARS] = OTTER;
				_bodyparts[FACE] = OTTER;
				_bodyparts[LEGS] = OTTER;
				_bodyparts[TAIL] = OTTER;
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
				if(_swim_fly<=-0.95)
					_swim_fly = -1.0;
				else
					_swim_fly-=0.05;
			}

			break;
			
		case(RABBIT):
			_animal_behaviors = _animal_behaviors | F_RABBIT;
			if(_type< NEU_CHAOS){
				_bodyparts[ARMS] = RABBIT;
				if(_bodyparts[HORNS]==NOAN)
					_bodyparts[EARS] = RABBIT;
				_bodyparts[LEGS] = RABBIT;
				_bodyparts[TAIL] = RABBIT;
			}
			increase_stat(FLY, 8);
			increase_stat(RUN, 40);
			increase_stat(POWER, -16);

			if(_type==CHILD){
				if(_run_power<=-0.9)
					_run_power = -1.0;
				else
					_run_power-=0.1;
			}else{
				if(_run_power<=-0.95)
					_run_power = -1.0;
				else
					_run_power-=0.05;
			}

			break;
			
		case(CHEETAH):
			_animal_behaviors = _animal_behaviors | F_CHEETAH;
			if(_type< NEU_CHAOS){
				_bodyparts[ARMS] = CHEETAH;
				if(_bodyparts[HORNS]==NOAN)
					_bodyparts[EARS] = CHEETAH;
				_bodyparts[LEGS] = CHEETAH;
				_bodyparts[TAIL] = CHEETAH;
			}
			increase_stat(SWIM, -8);
			increase_stat(FLY, -8);
			increase_stat(RUN, 40);
			increase_stat(POWER, 8);

			if(_type==CHILD){
				if(_run_power<=-0.9)
					_run_power = -1.0;
				else
					_run_power-=0.1;
			}else{
				if(_run_power<=-0.95)
					_run_power = -1.0;
				else
					_run_power-=0.05;
			}

			break;
		
		case(WARTHOG):
			_animal_behaviors = _animal_behaviors | F_WARTHOG;
			if(_type< NEU_CHAOS){
				_bodyparts[ARMS] = WARTHOG;
				if(_bodyparts[HORNS]==NOAN)
					_bodyparts[EARS] = WARTHOG;
				_bodyparts[FACE] = WARTHOG;
				_bodyparts[LEGS] = WARTHOG;
				_bodyparts[TAIL] = WARTHOG;
			}
			increase_stat(SWIM, -4);
			increase_stat(FLY, -12);
			increase_stat(RUN, 32);
			increase_stat(POWER, 16);

			if(_type==CHILD){
				if(_run_power<=-0.9)
					_run_power = -1.0;
				else
					_run_power-=0.1;
			}else{
				if(_run_power<=-0.95)
					_run_power = -1.0;
				else
					_run_power-=0.05;
			}

			break;
			
		case(BEAR):
			_animal_behaviors = _animal_behaviors | F_BEAR;
			if(_type< NEU_CHAOS){
				_bodyparts[ARMS] = BEAR;
				if(_bodyparts[HORNS]==NOAN)
					_bodyparts[EARS] = BEAR;
				_bodyparts[LEGS] = BEAR;
			}
			increase_stat(SWIM, 8);
			increase_stat(FLY, -16);
			increase_stat(RUN, 4);
			increase_stat(POWER, 36);

			if(_type==CHILD){
				if(_run_power>=0.9)
					_run_power = 1.0;
				else
					_run_power+=0.1;
			}else{
				if(_run_power>= 0.95)
					_run_power = 1.0;
				else
					_run_power+=0.05;
			}

			break;
			
		case(TIGER):
			_animal_behaviors = _animal_behaviors | F_TIGER;
			if(_type< NEU_CHAOS){
				_bodyparts[ARMS] = TIGER;
				if(_bodyparts[HORNS]==NOAN)
					_bodyparts[EARS] = TIGER;
				_bodyparts[LEGS] = TIGER;
				_bodyparts[TAIL] = TIGER;
			}
			increase_stat(SWIM, -8);
			increase_stat(FLY, -16);
			increase_stat(RUN, 20);
			increase_stat(POWER, 36);

            if(_type==CHILD){
                if(_run_power>=0.9)
                    _run_power = 1.0; 
                else
                    _run_power+=0.1;
            }else{
                if(_run_power>= 0.95)
                    _run_power = 1.0; 
                else
                    _run_power+=0.05;
            }

			break;
			
		case(GORILLA):
			_animal_behaviors = _animal_behaviors | F_GORILLA;
			if(_type< NEU_CHAOS){
				_bodyparts[ARMS] = GORILLA;
				if(_bodyparts[HORNS]==NOAN)
					_bodyparts[EARS] = GORILLA;
				_bodyparts[FOREHEAD] = GORILLA;
				_bodyparts[LEGS] = GORILLA;
			}
			increase_stat(SWIM, -4);
			increase_stat(FLY, -8);
			increase_stat(RUN, 4);
			increase_stat(POWER, 40);

            if(_type==CHILD){
                if(_run_power>=0.9)
                    _run_power = 1.0; 
                else
                    _run_power+=0.1;
            }else{
                if(_run_power>= 0.95)
                    _run_power = 1.0; 
                else
                    _run_power+=0.05;
            }

			break;
			
		case(PEACOCK):
			_animal_behaviors = _animal_behaviors | F_PEACOCK;
			if(_type< NEU_CHAOS){
				_bodyparts[FOREHEAD] = PEACOCK;
				_bodyparts[LEGS] = PEACOCK;
				_bodyparts[TAIL] = PEACOCK;
				_bodyparts[WINGS] = PEACOCK;
			}
			increase_stat(SWIM, 12);
			increase_stat(FLY, 48);
			increase_stat(RUN, -16);
			increase_stat(POWER, -12);

			if(_type==CHILD){
				if(_swim_fly>=0.9)
					_swim_fly = 1.0;
				else
					_swim_fly+=0.1;
			}else{
				if(_swim_fly>=0.95)
					_swim_fly = 1.0;
				else
					_swim_fly+=0.05;
			}

			break;
			
		case(PARROT):
			_animal_behaviors = _animal_behaviors | F_PARROT;
			if(_type< NEU_CHAOS){
				_bodyparts[FOREHEAD] = PARROT;
				_bodyparts[TAIL] = PARROT;
				_bodyparts[LEGS] = PARROT;
				_bodyparts[WINGS] = PARROT;
			}
			increase_stat(FLY, 48);
			increase_stat(RUN, -20);
			increase_stat(POWER, 4);

			if(_type==CHILD){
				if(_swim_fly>=0.9)
					_swim_fly = 1.0;
				else
					_swim_fly+=0.1;
			}else{
				if(_swim_fly>=0.95)
					_swim_fly = 1.0;
				else
					_swim_fly+=0.05;
			}

			break;
		
		case(CONDOR):
			_animal_behaviors = _animal_behaviors | F_CONDOR;
			if(_type< NEU_CHAOS){
				if(_bodyparts[HORNS]==NOAN)
					_bodyparts[EARS] = CONDOR;
				_bodyparts[LEGS] = CONDOR;
				_bodyparts[TAIL] = CONDOR;
				_bodyparts[LEGS] = CONDOR;
			}
			increase_stat(SWIM, 20);
			increase_stat(FLY, 60);
			increase_stat(RUN, -24);
			increase_stat(POWER, 16);

			if(_type==CHILD){
				if(_swim_fly>=0.9)
					_swim_fly = 1.0;
				else
					_swim_fly+=0.1;
			}else{
				if(_swim_fly>=0.95)
					_swim_fly = 1.0;
				else
					_swim_fly+=0.05;
			}

			break;
			
		case(SKUNK):
			_animal_behaviors = _animal_behaviors | F_SKUNK;
			if(_type< NEU_CHAOS){
				_bodyparts[ARMS] = SKUNK;
				_bodyparts[FOREHEAD] = SKUNK;
				_bodyparts[LEGS] = SKUNK;
				_bodyparts[TAIL] = SKUNK;
			}
			increase_stat(SWIM, 8);
			increase_stat(FLY, 12);
			increase_stat(RUN, 12);
			increase_stat(POWER, 8);

			if(_type==CHILD)
				move_transformation(RANDOM, 0.1);
			else
				move_transformation(RANDOM, 0.05);

			break;
			
		case(SHEEP):
			_animal_behaviors = _animal_behaviors | F_SHEEP;
			if(_type< NEU_CHAOS){
				_bodyparts[ARMS] = SHEEP;
				_bodyparts[EARS] = SHEEP;
				_bodyparts[LEGS] = SHEEP;
				_bodyparts[HORNS] = SHEEP;
				_bodyparts[TAIL] = SHEEP;
			}
			increase_stat(SWIM, 8);
			increase_stat(FLY, 12);
			increase_stat(RUN, 20);
			increase_stat(POWER, 20);

			if(_type==CHILD)
				move_transformation(RANDOM, 0.1);
			else
				move_transformation(RANDOM, 0.05);


			break;
			
		case(RACCOON):
			_animal_behaviors = _animal_behaviors | F_RACCOON;
			if(_type< NEU_CHAOS){
				_bodyparts[ARMS] = RACCOON;
				if(_bodyparts[HORNS]==NOAN)
					_bodyparts[EARS] = RACCOON;
				_bodyparts[LEGS] = RACCOON;
			}
			increase_stat(SWIM, 20);
			increase_stat(FLY, 12);
			increase_stat(RUN, 4);
			increase_stat(POWER, 8);

			if(_type==CHILD){
				move_transformation(RANDOM, 0.1);
			}else{
				move_transformation(RANDOM, 0.05);
			}

			break;
		
		case(DRAGON):
			_animal_behaviors = _animal_behaviors | F_DRAGON;
			if(_type< NEU_CHAOS){
				_bodyparts[ARMS] = DRAGON;
				_bodyparts[EARS] = DRAGON;
				_bodyparts[LEGS] = DRAGON;
				_bodyparts[HORNS] = DRAGON;
				_bodyparts[TAIL] = DRAGON;
				_bodyparts[WINGS] = DRAGON;
			}
			increase_stat(SWIM, 20);
			increase_stat(FLY, 4);
			increase_stat(RUN, 8);
			increase_stat(POWER, 32);

			if(_type==CHILD){
				move_transformation(RANDOM, 0.1);
			}else{
				move_transformation(RANDOM, 0.05);
			}

			break;
		
		case(PHOENIX):
			_animal_behaviors = _animal_behaviors | F_PHOENIX;
			if(_type< NEU_CHAOS){
				_bodyparts[FOREHEAD] = PHOENIX;
				_bodyparts[LEGS] = PHOENIX;
				_bodyparts[TAIL] = PHOENIX;
				_bodyparts[WINGS] = PHOENIX;
			}
			increase_stat(SWIM, 12);
			increase_stat(FLY, 32);
			increase_stat(RUN, 4);
			increase_stat(POWER, 16);

			if(_type==CHILD){
				move_transformation(RANDOM, 0.1);
			}else{
				move_transformation(RANDOM, 0.05);
			}

			break;
		
		case(UNICORN):
			_animal_behaviors = _animal_behaviors | F_UNICORN;
			if(_type< NEU_CHAOS){
				_bodyparts[ARMS] = UNICORN;
				if(_bodyparts[HORNS]==NOAN)
					_bodyparts[EARS] = UNICORN;
				_bodyparts[FOREHEAD] = UNICORN;
				_bodyparts[LEGS] = UNICORN;
				_bodyparts[TAIL] = UNICORN;
			}
			increase_stat(SWIM, 16);
			increase_stat(FLY, 12);
			increase_stat(RUN, 36);

			if(_type==CHILD){
				move_transformation(RANDOM, 0.1);
			}else{
				move_transformation(RANDOM, 0.05);
			}

			break;
			
		case(BAT):
			_animal_behaviors = _animal_behaviors | F_BAT;
			if(_type< NEU_CHAOS){
				_bodyparts[LEGS] = NOAN;
				_bodyparts[TAIL] = NOAN;
				_bodyparts[WINGS] = NOAN;

				_hidden_feet = true;
			}
			increase_stat(SWIM, 8);
			increase_stat(FLY, 40);
			increase_stat(RUN, 8);
			increase_stat(POWER, 8);

			if(_type==CHILD){
				move_transformation(RANDOM, 0.1);
			}else{
				move_transformation(RANDOM, 0.05);
			}

			break;
		
		case(HALFFISH):
			_animal_behaviors = _animal_behaviors | F_HALFFISH;
			if(_type< NEU_CHAOS){
				_emotiball = FLAME;
			}
			increase_stat(SWIM, 32);
			increase_stat(RUN, 8);
			increase_stat(POWER, 24);

			if(_type==CHILD){
				move_transformation(RANDOM, 0.1);
			}else{
				move_transformation(RANDOM, 0.05);
			}

			break;
			
		case(SKELETONDOG):
			_animal_behaviors = _animal_behaviors | F_SKELETONDOG;
			if(_type< NEU_CHAOS){
				remove_animalpart();
			}

			increase_stat(SWIM, 8);
			increase_stat(FLY, 8);
			increase_stat(RUN, 32);
			increase_stat(POWER, 16);

			if(_type==CHILD){
				move_transformation(RANDOM, 0.1);
			}else{
				move_transformation(RANDOM, 0.05);
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
	_medals[medal_prize-1]= true;

}

void Chao::race(uint8_t course){
	//TODO: algorithm + call win()
	switch(course){
	};
}

void Chao::karate(uint8_t lvl){//0-3 tournament lvl
	//TODO: perfect algorithm to include all stats
	uint16_t me = _points[STAMINA]/3000*21;
	lvl*=5;
	for(int i=0;i<5;i++){
		srand(time(NULL));

		float y = 1/(1+exp(lvl-me));
		y*=100;

		int x = rand()%100;


		if(x<y){
			cout<<"Congrats! You won!"<<endl;
			lvl++;
			_wins++;
			if(lvl>_karate_lvl)
				_karate_lvl=lvl;
		}else if(x>y){
			cout <<"You lost."<<endl<<endl;
			_losses++;
			return;
		}else{
			cout<<"You tied."<<endl<<endl;
			_draws++;
			return;
		}
	}
	cout<<"Congratulations! You won the tournament!"<<endl<<endl;
}

void Chao::learn(uint8_t lesson)
{
	_classroom_skills = _classroom_skills | lesson;

}

void Chao::medicine(uint8_t sickness)
{
	switch(sickness){
		case COUGH:
			cout<<"You're coughing a lot. I'll give you some cough drops."<<endl;
			_health[COUGH] = 100;
			break;
		case COLD:
			cout<<"Looks like you have a cold. I'll give you some medicine."<<endl;
			_health[COLD] = 100;
			break;
		case RASH:
			cout<<"Looks like you have a rash. Don't itch it!"<<endl;
			_health[RASH] = 100;
			break;
		case RUNNY_NOSE:
			cout<<"You have a runny nose. Don't forget to brush when you go home."<<endl;
			_health[RUNNY_NOSE] = 100;
			break;
		case HICCUPS:
			cout<<"Looks like you have the hiccups. I will give you a remedy for that."<<endl;
			_health[HICCUPS] = 100;
			break;
		case STOMACH_ACHE:
			cout<<"Looks like you have a stomach ache. I'll give you stomach medicine."<<endl;
			_health[STOMACH_ACHE] = 100;
			break;
	};

	cout<<"Your Chao took the medicine."<<endl<<endl;

}

void Chao::personality()
{
	srand(time(NULL));
	vector<int> pers;
	int per;

	for(int i=0;i<5;i++){
		if((i!=NAIV_NOR) && _personality[i]>=46)
			pers.push_back(i);
		else if(i==NAIV_NOR && _personality[i]<=-46)
			pers.push_back(i);
		else if(i==CRY_ENERG && _personality[i]<=-46)
			pers.push_back(i);
	}
	if(pers.size()==0)
		cout<<"None";
	else{
		per = pers[rand()%pers.size()];

		switch(per){
			case NOR_CURIOUS:
				cout<<"Curious";
				break;
			case CRY_ENERG:
				if(_personality[CRY_ENERG]<0)
					cout<<"Crybaby";
				else
					cout<<"Energetic";
				break;
			case NAIV_NOR:
				cout<<"Naive";
				break;
			case NOR_EAT:
				cout<<"Big eater";
				break;
			case NOR_FRE:
				cout<< "Carefree";
		};
	}
}

void Chao::doctor()
{

	for(int i=0;i<5;i++){
		if(_health[i]<=-80)
			medicine(i);
	}

	srand(time(NULL));

	cout <<endl<< _name <<endl<<endl;

	cout<<"Attributes"<<endl;
	if(_type==CHILD || _type%3==2)
		cout << "Neutral"<<endl<<endl;
	else if(_type%3==1)
		cout << "Hero"<<endl<<endl;
	else
		cout << "Dark"<<endl<<endl;

	cout<<"Ability type"<<endl;
	if(_type==CHILD)
		cout<<"Child"<<endl<<endl;
	else if(_type>=NEU_NOR && _type<=DAR_NOR)
		cout<<"Normal type"<<endl<<endl;
    else if(_type>=NEU_SWI && _type<=DAR_SWI)
        cout<<"Swim type"<<endl<<endl;
    else if(_type>=NEU_FLY && _type<=DAR_FLY)
        cout<<"Fly type"<<endl<<endl;
    else if(_type>=NEU_RUN && _type<=DAR_RUN)
        cout<<"Run type"<<endl<<endl;
    else if(_type>=NEU_POW && _type<=DAR_POW)
        cout<<"Power type"<<endl<<endl;

	cout<<"\t\tSkill\tAbility"<<endl;
	cout<<"Swim\t\t"<< _points[SWIM]<<"\t"<<(uint16_t)_grades[SWIM]<<endl;
	cout<<"Fly\t\t"<< _points[FLY]<<"\t"<<(uint16_t)_grades[FLY]<<endl;
	cout<<"Run\t\t"<< _points[RUN]<<"\t"<<(uint16_t)_grades[RUN]<<endl;
	cout<<"Power\t\t"<< _points[POWER]<<"\t"<<(uint16_t)_grades[POWER]<<endl;
	cout<<"Stamina\t\t"<< _points[STAMINA]<<"\t"<<(uint16_t)_grades[STAMINA]<<endl<<endl;

	cout<<"Personality"<<endl;
	personality();
	cout<<endl<<endl;
	cout<<"Favorite"<<endl;
	cout << "Your Chao likes "<<(uint16_t)_fav_fruit<<" fruit."<<endl<<endl;
	cout<<"Age\t\tTimes transformed"<<endl;
	cout<<!(_type==CHILD)<<"\t\t"<<_reincarnations<<endl<<endl;

	cout<<"Record"<<endl<<endl;

	cout<<"Chao Race"<<endl;
	cout<<"[ ";
	for(int i=0;i<DARK_MEDAL;i++){
		if(_medals[i]==true)
			cout<<i+1;
		
		else
			cout<<0;
		cout<<" ";
	}
	cout<<"]"<<endl<<endl;

	cout<<"Chao Karate"<<endl;
	cout<<_wins<<" wins"<<endl;
	cout<<_losses<<" losses"<<endl;
	cout<<_draws<<" draws"<<endl;

	cout<<"Rank"<<endl;
	cout<<_karate_lvl<<endl<<endl;

}
