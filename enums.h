#ifndef ENUMS_H
#define ENUMS_H

enum {
	NO_GARDEN, CHAO_GARDEN, HERO_GARDEN, DARK_GARDEN
};


enum{
	EMPTY, EGG, CHILD, GOOD, BAD, NEU_NOR, HER_NOR, DAR_NOR, NEU_SWI, HER_SWI, DAR_SWI, NEU_FLY,
	HER_FLY, DAR_FLY, NEU_RUN, HER_RUN, DAR_RUN, NEU_POW, HER_POW, DAR_POW, NEU_CHAOS, 
	HER_CHAOS, DAR_CHAOS 
};

enum{
	E, D, C, B, A , S
};


enum{
	NORMAL, FLAME, NOBALL

};


enum{
	NORMAL_EYES, PAINFUL, CLOSED_STRAIGHT, CLOSED_HAPPY, CLOSED_UP, TINY, CIRCLES, CLOSED_DOWN,
	TINY_2, HALF_CLOSED, MEAN, GREEN_CHAOS, BLUE_CHAOS, YELLOW_CHAOS
};

enum{
	NOMEDAL, AQUA, TOPAZ, PERI, GAR, ONYX, DIA, BEG, CHALL, HERO_MEDAL, DARK_MEDAL, PEARL,
	AME, EMER, RUBY, SAPPHIRE
};


enum{
	TOOTHY, OPEN, CLOSED_SMILE, CLOSED_FROWN, OPEN_SMILE, OPEN_FROWN, CLOSED_SMILE2,
	SQUIGGLY, TOOTHY_FROWN, CLOSED_FROWN2, WIDE_OPEN, CLOSED_FROWN3, STRAIGHT_MOUST,
	SQUIGGLY_MOUST1, SQUIGGLY_MOUST2
};


enum{
	NORMAL_COLOR, YELLOW, WHITE, BROWN, SKY_BLUE, PINK, BLUE, GREY, GREEN, RED, LIME_GREEN,
	PURPLE, ORANGE, BLACK
};

enum{
	NORMAL_EGG, YELLOW_MONO, WHITE_MONO, BROWN_MONO, SKY_BLUE_MONO, PINK_MONO, BLUE_MONO,
	GREY_MONO, GREEN_MONO, RED_MONO, LIME_GREEN_MONO, PURPLE_MONO, ORANGE_MONO, BLACK_MONO,
	YELLOW_TWO, WHITE_TWO, BROWN_TWO, SKY_BLUE_TWO, PINK_TWO, BLUE_TWO, GREY_TWO, GREEN_TWO,
	RED_TWO, LIME_GREEN_TWO, PURPLE_TWO, ORANGE_TWO, BLACK_TWO,

	NORMAL_SHI, YELLOW_SHI_MONO, WHITE_SHI_MONO, BROWN_SHI_MONO, SKY_BLUE_SHI_MONO,
	PINK_SHI_MONO, BLUE_SHI_MONO, GREY_SHI_MONO, GREEN_SHI_MONO, RED_SHI_MONO, 
	LIME_GREEN_SHI_MONO, PURPLE_SHI_MONO, ORANGE_SHI_MONO, BLACK_SHI_MONO, YELLOW_SHI_TWO,
	WHITE_SHI_TWO, BROWN_SHI_TWO, SKY_BLUE_SHI_TWO,	PINK_SHI_TWO, BLUE_SHI_TWO, GREY_SHI_TWO, 
	GREEN_SHI_TWO, RED_SHI_TWO, LIME_GREEN_SHI_TWO,	PURPLE_SHI_TWO, ORANGE_SHI_TWO, BLACK_SHI_TWO

};

enum{
	NOTEXT, YELLOW_JWL, WHITE_JWL, PINK_JWL, BLUE_JWL, GREEN_JWL, PURPLE_JWL, SKY_BLUE_JWL,
	RED_JWL, BLACK_JWL, LIME_GREEN_JWL, ORANGE_JWL
};

enum{
	ROU_FRT1, ROU_FRT2, TRI_FRT1, TRI_FRT2, SQ_FRT1, SQ_FRT2, NONE1, NONE2
};

enum{
	NO_ABIL, DRAW1, DRAW2, DRAW3 = 1<<2, DRAW4 = 1<<3, DRAW5 = 1<<4, SHAKE = 1<<8,
	SPIN = 1<<9, STEP = 1<<10, GOGO = 1<<11, EXERCISE = 1<<12, SONG1 = 1<<16, SONG2 = 1<<17,
	SONG3 = 1<<18, SONG4 = 1<<19, SONG5 = 1<<20, BELL = 1<<24, CASTANETS = 1<<25, 
	CYMBALS = 1<<26, DRUM = 1<<27, FLUTE = 1<<28, MARACAS = 1<<29, TRUMPET = 1<<30,
	TAMBOURINE = 1<<31
};

enum{
	F_NOAN, F_PENGUIN, F_SEAL, F_OTTER = 1<<2, F_RABBIT = 1<<3, F_CHEETAH = 1<<4,
	F_WARTHOG = 1<<5, F_BEAR = 1<<6, F_TIGER = 1<<7, F_GORILLA = 1<<8, F_PEACOCK = 1<<9,
	F_PARROT = 1<<10, F_CONDOR = 1<<11, F_SKUNK = 1<<12, F_SHEEP = 1<<13, F_RACCOON = 1<<14,
	F_HALFFISH = 1<<15,	F_SKELETONDOG = 1<<16, F_BAT = 1<<17, F_DRAGON = 1<<18, 
	F_UNICORN = 1<<19, F_PHOENIX = 1<<20
};

enum{
	NOAN=255, PENGUIN=0, SEAL, OTTER, RABBIT, CHEETAH, WARTHOG, BEAR, TIGER, GORILLA, PEACOCK,
	PARROT,	CONDOR,	SKUNK, SHEEP, RACCOON, HALFFISH, SKELETONDOG, BAT, DRAGON, UNICORN, PHOENIX,
	YELLOW_DRIVE, GREEN_DRIVE, RED_DRIVE, PURPLE_DRIVE
};

enum{
	NO_TOY, RATTLE, CAR, BOOK = 1<<2, DOLL = 1<<4, BROOMSTICK = 1<<5, STICK =1<<7, 
	CRAYONS = 1<<8, WAND = 1<<9, SHOVEL = 1<<10, CAN = 1<11
};

enum{
	NO_FRT=255, CHAO_GAR_FRT=0, HERO_GAR_FRT, DARK_GAR_FRT, STRONG_FRT, TASTY_FRT, HERO_FRT,
	DARK_FRT, ROUND_FRT, TRIANGLE_FRT, SQUARE_FRT, HEART_FRT, CHAO_FRT, MUSHROOM=20
};

enum{
	NO_SEED = 255, STR_SEED=0, TASTY_SEED, HERO_SEED, DARK_SEED, ROUND_SEED, TRIANGLE_SEED,
	SQUARE_SEED
};

enum{
	NOHAT, PUMPKIN, SKULL, APPLE, BUCKET, EMPTY_CAN, BOX, POT, BAG, PAN, STUMP, WATERMELON,
	RED_BEANIE, BLUE_BEANIE, BLACK_BEANIE, PACIFIER,
	NORMAL_EGG_SH, YELLOW_MONO_SH, WHITE_MONO_SH, BROWN_MONO_SH, SKY_BLUE_MONO_SH, PINK_MONO_SH,
	BLUE_MONO_SH, GREY_MONO_SH, GREEN_MONO_SH, RED_MONO_SH,	LIME_GREEN_MONO_SH, PURPLE_MONO_SH,
	ORANGE_MONO_SH, BLACK_MONO_SH, YELLOW_TWO_SH, WHITE_TWO_SH, BROWN_TWO_SH, SKY_BLUE_TWO_SH,
	PINK_TWO_SH, BLUE_TWO_SH, GREY_TWO_SH, GREEN_TWO_SH, RED_TWO_SH, LIME_GREEN_TWO_SH,
	PURPLE_TWO_SH, ORANGE_TWO_SH, BLACK_TWO_SH, NORMAL_SHI_SH, YELLOW_SHI_MONO_SH,
	WHITE_SHI_MONO_SH, BROWN_SHI_MONO_SH, SKY_BLUE_SHI_MONO_SH, PINK_SHI_MONO_SH,
	BLUE_SHI_MONO_SH, GREY_SHI_MONO_SH, GREEN_SHI_MONO_SH, RED_SHI_MONO_SH,
	LIME_GREEN_SHI_MONO_SH, PURPLE_SHI_MONO_SH, ORANGE_SHI_MONO_SH, BLACK_SHI_MONO_SH,
	YELLOW_SHI_TWO_SH,	WHITE_SHI_TWO_SH, BROWN_SHI_TWO_SH, SKY_BLUE_SHI_TWO_SH, PINK_SHI_TWO_SH,
	BLUE_SHI_TWO_SH, GREY_SHI_TWO_SH, GREEN_SHI_TWO_SH, RED_SHI_TWO_SH, LIME_GREEN_SHI_TWO_SH,
	PURPLE_SHI_TWO_SH, ORANGE_SHI_TWO_SH, BLACK_SHI_TWO_SH
};

enum{
	SWIM, FLY, RUN, POWER, STAMINA, LUCK, INTELLIGENCE
};

enum{
	ARMS, EARS, FOREHEAD, HORNS, LEGS, TAIL, WINGS, FACE
};


#endif /* ENUMS_H */