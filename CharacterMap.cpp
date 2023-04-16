#pragma once
#include <cstddef>
#include "CharacterMap.h"

	/*CharacterMap::CharacterMap(unsigned char aCharacter, int aFrequency) noexcept
		: fCharacter(aCharacter), fFrequency(aFrequency)
	{
	}*/


	CharacterMap::CharacterMap(unsigned char aCharacter, int aFrequency) noexcept
	{
		fCharacter = aCharacter;
		fFrequency = aFrequency;
	}

	//add one to the frequency
	void CharacterMap::increment() noexcept {
		++fFrequency;
	}

	void CharacterMap::setCharacter(unsigned char aCharacter) noexcept {
		//assigns a desired character to the map
		fCharacter = aCharacter;
	}

	bool CharacterMap::operator<(const CharacterMap& aOther) const noexcept {
		//compares the frequency of the current map to the frequency of the other map
		return fFrequency < aOther.fFrequency;
	}
	unsigned char CharacterMap::character() const noexcept {
		//returns the character of the map
		return fCharacter;
	}
	size_t CharacterMap::frequency() const noexcept {
		//returns the frequency of the map
		return fFrequency;
	}
