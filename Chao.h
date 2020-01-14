#ifndef CHAO_H
#define CHAO_H

#include <cstdint>
#include <string>
#include "enums.h"

class Chao
{
	std::string _name;
	uint8_t _garden;
	int8_t _happiness;
	bool _reset;
	uint16_t _rem_lifespan1;
	uint16_t _rem_lifespan2;
	uint16_t _reincarnations;
	uint32_t _animal_behaviors;
	unsigned int _classroom_skills;
	uint16_t _toys;

	uint8_t _type;
	float _alignment;
	float _run_power;
	float _swim_fly;
	float _transformation_magnitude;

	uint8_t _bars[7];

	uint8_t _grades[7];

	uint8_t _levels[7];

	uint16_t _points[7];

	uint8_t _color;
	bool _monotone;
	uint8_t _texture;
	bool _shiny;
	uint8_t _egg_color;
	uint8_t _medal;
	uint8_t _hat;
	uint8_t _eyes;
	uint8_t _mouth;
	uint8_t _emotiball;
	bool _hidden_feet;

	uint8_t _bodyparts[8];

	uint8_t _grades1[7];
	uint8_t _grades2[7];

	uint8_t _fav_fruit1;
	uint8_t _fav_fruit2;
	uint8_t _color1;
	uint8_t _color2;
	bool _monotone1;
	bool _monotone2;
	uint8_t _texture1;
	uint8_t _texture2;
	bool _shiny1;
	bool _shiny2;
	uint8_t _egg_color1;
	uint8_t _egg_color2;

	int8_t _bonds[6];

	uint16_t _mating;
	uint16_t _hunger;
	uint16_t _sleepiness;
	uint16_t _tiredness;
	uint16_t _boredom;
	uint16_t _energy;

	uint8_t _joy;
	uint8_t _cry;
	uint8_t _fear;
	uint8_t _dizziness;

	int8_t _cough;
	int8_t _cold;
	int8_t _rash;
	int8_t _runny_nose;
	int8_t _hiccups;
	int8_t _stomach_ache;

	uint8_t _fav_fruit;

	int8_t _normal_curious;
	int8_t _kindness;
	int8_t _crybaby_energetic;
	int8_t _naive_normal;
	int8_t _sollitude;
	int8_t _vitality;
	int8_t _normal_bigeater;
	int8_t _regain;
	int8_t _skillful;
	int8_t _charm;
	int8_t _chatty;
	int8_t _normal_carefree;
	int8_t _fickle;


	void increase_stat(uint8_t stat, uint8_t val);
	void heart(uint8_t character);

public:
	Chao(uint8_t egg_colour);
	Chao(Chao parent1, Chao parent2);

	int8_t happiness(){ return _happiness;}

	void reset();
	void born(){ _type=CHILD; }
	uint8_t evolve();
	bool die();


	void name_chao(std::string name);
	void eat(uint8_t fruit, uint8_t character);
	void pet(uint8_t character);
	void pickup(uint8_t character);
	void drop(uint8_t garden);
	void thrown(uint8_t character);
	void abuse(uint8_t character);
	void take_animal(uint8_t animal, uint8_t character);
	void take_drive(uint8_t color, uint8_t character);
	void take_hat(uint8_t hat);
	void win(uint8_t medal, uint8_t toy);
	void learn(uint8_t lesson);
	void medicine(uint8_t sickness);

};

Chao mate(Chao& chao1, Chao& chao2);
bool die(Chao& chao);


#endif /* CHAO_H */
