#pragma once
#include <math.h>

namespace glm {

	// forward declarations
	template <typename T> class vec2_T;
	template <typename T> class vec3_T;
	// template <typename T> class vec4_T;
	// template <typename T> class vec5_T;

	// cross2
	template <typename T>
	T cross(const vec2_T<T>& v1, const vec2_T<T>& v2)
	{
		return (v1.x * v2.y) - (v1.y * v2.x);
	}

	// cross3
	template <typename T>
	vec3_T<T> cross(const vec3_T<T>& v1, const vec3_T<T>& v2)
	{
		return vec3_T<T>(
			(v1.y * v2.z) - (v1.z * v2.y),
			(v1.z * v2.x) - (v1.x * v2.z),
			(v1.x * v2.y) - (v1.y * v2.x));
	}

	template <typename T, typename U>
	vec3_T<T> cross(const vec3_T<T>& v1, const vec3_T<U>& v2)
	{
		return vec3_T<T>(
			(v1.y * static_cast<T>(v2.z)) - (v1.z * static_cast<T>(v2.y)),
			(v1.z * static_cast<T>(v2.x)) - (v1.x * static_cast<T>(v2.z)),
			(v1.x * static_cast<T>(v2.y)) - (v1.y * static_cast<T>(v2.x)));
	}

	// cross4

	// distance2
	template <typename T>
	T distance(const vec2_T<T>& v1, const vec2_T<T>& v2)
	{
		return static_cast<T>(sqrt(
			(v1.x - v2.x) * (v1.x - v2.x) +
			(v1.y - v2.y) * (v1.y - v2.y)));
	}

	template <typename T, typename U>
	T distance(const vec2_T<T>& v1, const vec2_T<U>& v2)
	{
		return static_cast<T>(sqrt(
			(v1.x - static_cast<T>(v2.x)) * (v1.x - static_cast<T>(v2.x)) +
			(v1.y - static_cast<T>(v2.y)) * (v1.y - static_cast<T>(v2.y))));
	}

	// distance3
	template <typename T>
	T distance(const vec3_T<T>& v1, const vec3_T<T>& v2)
	{
		return static_cast<T>(sqrt(
			(v1.x - v2.x) * (v1.x - v2.x) +
			(v1.y - v2.y) * (v1.y - v2.y) +
			(v1.z - v2.z) * (v1.z - v2.z)));
	}

	template <typename T, typename U>
	T distance(const vec3_T<T>& v1, const vec3_T<U>& v2)
	{
		return static_cast<T>(sqrt(
			(v1.x - static_cast<T>(v2.x)) * (v1.x - static_cast<T>(v2.x)) +
			(v1.y - static_cast<T>(v2.y)) * (v1.y - static_cast<T>(v2.y)) +
			(v1.z - static_cast<T>(v2.z)) * (v1.z - static_cast<T>(v2.z))));
	}

	// distance4
	// distance5

	// dot2
	template <typename T>
	T dot(const vec2_T<T>& v1, const vec2_T<T>& v2)
	{
		return (v1.x * v2.x) + (v1.y * v2.y);
	}

	template <typename T, typename U>
	T dot(const vec2_T<T>& v1, const vec2_T<U>& v2)
	{
		return (v1.x * static_cast<T>(v2.x)) + (v1.y * static_cast<T>(v2.y));
	}

	// dot3
	template <typename T>
	T dot(const vec3_T<T>& v1, const vec3_T<T>& v2)
	{
		return (v1.x * v2.x) + (v1.y * v2.y) + (v1.z * v2.z);
	}

	template <typename T, typename U>
	T dot(const vec3_T<T>& v1, const vec3_T<U>& v2)
	{
		return (v1.x * static_cast<T>(v2.x)) + (v1.y * static_cast<T>(v2.y)) + (v1.z * static_cast<T>(v2.z));
	}

	// dot4
	// dot5

	// length2
	template <typename T>
	T length(const vec2_T<T>& v)
	{
		return static_cast<T>(sqrt(dot(v, v)));
	}

	// length3
	template <typename T>
	T length(const vec3_T<T>& v)
	{
		return static_cast<T>(sqrt(dot(v, v)));
	}

	// length4
	// length5

	// reflect2
	template <typename T>
	vec2_T<T> reflect(const vec2_T<T>& I, const vec2_T<T>& N)
	{
		return I - N * dot(N, I) * static_cast<T>(2);
	}

	template <typename T, typename U>
	vec2_T<T> reflect(const vec2_T<T>& I, const vec2_T<U>& N)
	{
		return I - N * dot(N, I) * static_cast<T>(2);
	}

	// reflect3
	template <typename T>
	vec3_T<T> reflect(const vec3_T<T>& I, const vec3_T<T>& N)
	{
		return I - N * dot(N, I) * static_cast<T>(2);
	}

	template <typename T, typename U>
	vec3_T<T> reflect(const vec3_T<T>& I, const vec3_T<U>& N)
	{
		return I - N * dot(N, I) * static_cast<T>(2);
	}

	// reflect4

}
