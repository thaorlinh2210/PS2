#pragma once
#include "CharacterCounter.h"
//#include "CharacterMap.h"
#include <iostream>

using namespace std;


CharacterCounter::CharacterCounter() noexcept
{
	fTotalNumberOfCharacters = 0;
	for (int i = 0; i < 256; i++)
	{
		fCharacterCounts[i].setCharacter(i);
	}
}

void CharacterCounter::count(unsigned char aCharacter) noexcept 
{
// takes a character and increments the frequency of the character in the map
	fCharacterCounts[aCharacter].increment();
}
const CharacterMap& CharacterCounter::operator[](unsigned char aCharacter) const noexcept {
	//returns the map of the character
	return fCharacterCounts[aCharacter];
}

