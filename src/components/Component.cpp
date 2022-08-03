#include "Component.hpp"
#include "UniqueID.hpp"

namespace Patchwork {
	uint32_t Component::GetID() const {
		return kID_;
	}

	Component::Component() 
		: kID_(UniqueID::GenerateID()) {}
	Component::~Component() {}
}