#pragma once
#include <math.h>

namespace glm {

	// forward declarations
	// template <typename T> class vec2;
	template <typename T> class vec3;
	// template <typename T> class vec4;
	// template <typename T> class vec5;

	// cross2
	// cross3
	template <typename T>
	vec3<T> cross(const vec3<T>& v1, const vec3<T>& v2)
	{
		return vec3<T>(
			(v1.y * v2.z) - (v1.z * v2.y),
			(v1.z * v2.x) - (v1.x * v2.z),
			(v1.x * v2.y) - (v1.y * v2.x));
	}

	template <typename T, typename U>
	vec3<T> cross(const vec3<T>& v1, const vec3<U>& v2)
	{
		return vec3<T>(
			(v1.y * static_cast<T>(v2.z)) - (v1.z * static_cast<T>(v2.y)),
			(v1.z * static_cast<T>(v2.x)) - (v1.x * static_cast<T>(v2.z)),
			(v1.x * static_cast<T>(v2.y)) - (v1.y * static_cast<T>(v2.x)));
	}

	// cross4

	// distance2
	// distance3
	template <typename T>
	T distance(const vec3<T>& v1, const vec3<T>& v2)
	{
		return static_cast<T>(sqrt(
			(v1.x - v2.x) * (v1.x - v2.x) +
			(v1.y - v2.y) * (v1.y - v2.y) +
			(v1.z - v2.z) * (v1.z - v2.z)));
	}

	template <typename T, typename U>
	T distance(const vec3<T>& v1, const vec3<U>& v2)
	{
		return static_cast<T>(sqrt(
			(v1.x - static_cast<T>(v2.x)) * (v1.x - static_cast<T>(v2.x)) +
			(v1.y - static_cast<T>(v2.y)) * (v1.y - static_cast<T>(v2.y)) +
			(v1.z - static_cast<T>(v2.z)) * (v1.z - static_cast<T>(v2.z))));
	}

	// distance4
	// distance5

	// dot2
	// dot3
	template <typename T>
	T dot(const vec3<T>& v1, const vec3<T>& v2)
	{
		return (v1.x * v2.x) + (v1.y * v2.y) + (v1.z * v2.z);
	}

	template <typename T, typename U>
	T cross(const vec3<T>& v1, const vec3<U>& v2)
	{
		return (v1.x * static_cast<T>(v2.x)) + (v1.y * static_cast<T>(v2.y)) + (v1.z * static_cast<T>(v2.z));
	}

	// dot4
	// dot5

	// length2
	// length3
	template <typename T>
	T length(const vec3<T>& v)
	{
		return static_cast<T>(sqrt(dot(v, v)));
	}

	// length4
	// length5

	// reflect2
	// reflect3
	template <typename T>
	vec3<T> reflect(const vec3<T>& I, const vec3<T>& N)
	{
		return I - N * dot(N, I) * static_cast<T>(2);
	}

	template <typename T, typename U>
	vec3<T> reflect(const vec3<T>& I, const vec3<U>& N)
	{
		return I - N * dot(N, I) * static_cast<T>(2);
	}

	// reflect4

}
