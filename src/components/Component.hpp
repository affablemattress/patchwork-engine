#pragma once
#include <stdint.h>

namespace Patchwork {
	class Component {
	public:
		const static enum Type {
			Transform = 0,
			Renderer = 1,
			Camera = 2
		};
		virtual Type GetType() const = 0;
		//@return Program-wide unique uint32 ID to the component
		uint32_t GetID() const;

		Component();
		virtual ~Component();
	private:
		const uint32_t kID_;
	};
}
