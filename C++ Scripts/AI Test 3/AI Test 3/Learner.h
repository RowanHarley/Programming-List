#ifndef _LEARNER_H
#define _LEARNER_H

#include <iostream>
#include <fstream>
#include "Voice.h"

class Learner{
public:
	Voice voice;
	void respond(string phrase);
	void say(string phrase);
};
#endif
