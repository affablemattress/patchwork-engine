#include "UniqueID.hpp"

namespace Patchwork {
	uint32_t UniqueID::GenerateID() {
		lastID_++;
		return lastID_;
	}
}