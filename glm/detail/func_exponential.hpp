#pragma once
#include <math.h>
#include "vec2.hpp"
#include "vec3.hpp"
#include "vec4.hpp"
#include "vec5.hpp"

namespace glm
{
	// forward declarations
	template <typename T> class vec2_T;
	template <typename T> class vec3_T;
	template <typename T> class vec4_T;
	template <typename T> class vec5_T;

	// exp

	// exp2

	// inversesqrt
	template <typename T>
	T inversesqrt(T x)
	{
		return static_cast<T>(1) / std::sqrt(x);
	}

	// log

	// log2

	// pow

	// sqrt
	template <typename T>
	vec2_T<T> sqrt(const vec2_T<T>& v)
	{
		return vec2_T<T>(
			static_cast<T>(std::sqrt(v.x)),
			static_cast<T>(std::sqrt(v.y)));
	}

	template <typename T>
	vec3_T<T> sqrt(const vec3_T<T>& v)
	{
		return vec3_T<T>(
			static_cast<T>(std::sqrt(v.x)),
			static_cast<T>(std::sqrt(v.y)),
			static_cast<T>(std::sqrt(v.z)));
	}

	template <typename T>
	vec4_T<T> sqrt(const vec4_T<T>& v)
	{
		return vec4_T<T>(
			static_cast<T>(std::sqrt(v.x)),
			static_cast<T>(std::sqrt(v.y)),
			static_cast<T>(std::sqrt(v.z)),
			static_cast<T>(std::sqrt(v.w)));
	}

	template <typename T>
	vec5_T<T> sqrt(const vec5_T<T>& v)
	{
		return vec5_T<T>(
			static_cast<T>(std::sqrt(v.x)),
			static_cast<T>(std::sqrt(v.y)),
			static_cast<T>(std::sqrt(v.z)),
			static_cast<T>(std::sqrt(v.w)),
			static_cast<T>(std::sqrt(v.v)));
	}
}
