#pragma once
#include <cstddef>
#include "CharacterCounter.h"
class CharacterMap
{
private:
	unsigned char fCharacter;
	size_t fFrequency;
public:
	CharacterMap(unsigned char aCharacter = '\0',
		int aFrequency = 0) noexcept;
	void increment() noexcept;
	void setCharacter(unsigned char aCharacter) noexcept;
	bool operator<(const CharacterMap& aOther) const noexcept;
	unsigned char character() const noexcept;
	size_t frequency() const noexcept;
};