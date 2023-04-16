#pragma once
#include "CharacterCounter.h"
#include "CharacterFrequencyIterator.h"

CharacterFrequencyIterator::CharacterFrequencyIterator(const CharacterCounter* aCollection) noexcept
	
{
	fCollection = aCollection;
	fIndex = 0;
	for (size_t i = 0; i < 256; ++i) {
		fMappedIndices[i] = i;
	}
	mapIndices();
}

void CharacterFrequencyIterator::mapIndices() noexcept {
	//maps the indices of the character map to the indices of the mapped indices
	for (size_t i = 0; i < 256; ++i) 
	{
		fMappedIndices[i] = i;
	}
	//insertion sort
	for (size_t i = 1; i < 256; ++i) {
		size_t j = i;
		while (j > 0 && (*fCollection)[fMappedIndices[j - 1]] < (*fCollection)[fMappedIndices[j]]) {
			unsigned char temp = fMappedIndices[j];
			fMappedIndices[j] = fMappedIndices[j - 1];
			fMappedIndices[j - 1] = temp;
			--j;
		}
	}

	/*for (size_t i = 0; i < 256; ++i) {
		for (size_t j = i + 1; j < 256; ++j) {
			if ((*fCollection)[fMappedIndices[i]] < (*fCollection)[fMappedIndices[j]]) {
				unsigned char temp = fMappedIndices[i];
				fMappedIndices[i] = fMappedIndices[j];
				fMappedIndices[j] = temp;
			}
		}
	}*/
}

const CharacterMap& CharacterFrequencyIterator::operator*() const noexcept 
{
	
	//returns the map of the character
	return (*fCollection)[fMappedIndices[fIndex]];
}

CharacterFrequencyIterator& CharacterFrequencyIterator::operator++() noexcept 
{
	//increments the index
	++fIndex;
	return *this;
}

CharacterFrequencyIterator CharacterFrequencyIterator::operator++(int) noexcept 
{
	//increments the index
	CharacterFrequencyIterator temp = *this;
	++fIndex;
	return temp;
}

bool CharacterFrequencyIterator::operator==(const CharacterFrequencyIterator& aOther) const noexcept 
{
	//compares the index of the current iterator to the index of the other iterator
	return fIndex == aOther.fIndex;
}

bool CharacterFrequencyIterator::operator!=(const CharacterFrequencyIterator& aOther) const noexcept 
{
	//compares the index of the current iterator to the index of the other iterator
	return fIndex != aOther.fIndex;
}

CharacterFrequencyIterator CharacterFrequencyIterator::begin() const noexcept 
{
	//returns the iterator
	return *this;
}

CharacterFrequencyIterator CharacterFrequencyIterator::end() const noexcept 
{
	//return the end of the iterator
	CharacterFrequencyIterator temp = *this;
	temp.fIndex = 256;
	return temp;
}

