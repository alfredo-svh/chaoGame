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
	uint16_t _rem_lifespan;
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

	uint16_t _emotions[6];

	uint8_t _behaviors[4];

	int8_t _health[6];

	int8_t _personality[5];

	uint8_t _fav_fruit;

	bool _medals[DARK_MEDAL];
	uint8_t _karate_lvl;
	unsigned _wins;
	unsigned _losses;
	unsigned _draws;


	uint8_t evolve();
	bool die();
	void move_transformation(uint8_t stat, float value);
	void move_alignment(float value);
	void increase_stat(uint8_t stat, int8_t val);
	void remove_animalpart();
	void heart(uint8_t character);
	void medicine(uint8_t sickness);
	void personality();
	void win(uint8_t medal, uint8_t toy);

public:
	Chao(uint8_t egg_colour);
	Chao(Chao parent1, Chao parent2);

	int8_t happiness(){ return _happiness;}

	void born(uint8_t garden);
	void reset();
	void name_chao(std::string name);
	void eat(uint8_t fruit, uint8_t character);
	void pet(uint8_t character);
	void pickup(uint8_t character);
	void drop(uint8_t garden);
	void thrown(uint8_t character, uint8_t garden);
	void abuse(uint8_t character);
	void take_animal(uint8_t animal, uint8_t character);
	void take_drive(uint8_t color, uint8_t character);
	void take_hat(uint8_t hat);
	void race(uint8_t course);
	void karate(uint8_t lvl);
	void learn(uint8_t lesson);
	void doctor();

};

//Chao mate(Chao& chao1, Chao& chao2);
bool die(Chao& chao);


#endif /* CHAO_H */
