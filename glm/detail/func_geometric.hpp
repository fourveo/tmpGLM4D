#pragma once
#include <math.h>
#include <limits>
#include "func_exponential.hpp"
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
	template <typename T>
	vec4_T<T> cross(const vec4_T<T>& v1, const vec4_T<T>& v2, const vec4_T<T>& v3)
	{
		T t1 = (v2.z * v3.w) - (v2.w * v3.z);
		T t2 = (v2.y * v3.w) - (v2.w * v3.y);
		T t3 = (v2.y * v3.z) - (v2.z * v3.y);
		T t4 = (v2.x * v3.w) - (v2.w * v3.x);
		T t5 = (v2.x * v3.z) - (v2.z * v3.x);
		T t6 = (v2.x * v3.y) - (v2.y * v3.x);

		return vec4_T<T>(
			t1 * v1.y - t2 * v1.z + t3 * v1.w,
		  -(t1 * v1.x - t4 * v1.z + t5 * v1.w),
			t2 * v1.x - t4 * v1.y + t6 * v1.w,
		  -(t3 * v1.x - t5 * v1.y + t6 * v1.z));
	}

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
	template <typename T>
	T distance(const vec4_T<T>& v1, const vec4_T<T>& v2)
	{
		return static_cast<T>(sqrt(
			(v1.x - v2.x) * (v1.x - v2.x) +
			(v1.y - v2.y) * (v1.y - v2.y) +
			(v1.z - v2.z) * (v1.z - v2.z) +
			(v1.w - v2.w) * (v1.w - v2.w)));
	}

	template <typename T, typename U>
	T distance(const vec4_T<T>& v1, const vec4_T<U>& v2)
	{
		return static_cast<T>(sqrt(
			(v1.x - static_cast<T>(v2.x)) * (v1.x - static_cast<T>(v2.x)) +
			(v1.y - static_cast<T>(v2.y)) * (v1.y - static_cast<T>(v2.y)) +
			(v1.z - static_cast<T>(v2.z)) * (v1.z - static_cast<T>(v2.z)) +
			(v1.w - static_cast<T>(v2.w)) * (v1.w - static_cast<T>(v2.w))));
	}

	// distance5
	template <typename T>
	T distance(const vec5_T<T>& v1, const vec5_T<T>& v2)
	{
		return static_cast<T>(sqrt(
			(v1.x - v2.x) * (v1.x - v2.x) +
			(v1.y - v2.y) * (v1.y - v2.y) +
			(v1.z - v2.z) * (v1.z - v2.z) +
			(v1.w - v2.w) * (v1.w - v2.w) +
			(v1.v - v2.v) * (v1.v - v2.v)));
	}

	template <typename T, typename U>
	T distance(const vec5_T<T>& v1, const vec5_T<U>& v2)
	{
		return static_cast<T>(sqrt(
			(v1.x - static_cast<T>(v2.x)) * (v1.x - static_cast<T>(v2.x)) +
			(v1.y - static_cast<T>(v2.y)) * (v1.y - static_cast<T>(v2.y)) +
			(v1.z - static_cast<T>(v2.z)) * (v1.z - static_cast<T>(v2.z)) +
			(v1.w - static_cast<T>(v2.w)) * (v1.w - static_cast<T>(v2.w)) +
			(v1.w - static_cast<T>(v2.v)) * (v1.w - static_cast<T>(v2.v))));
	}

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
	template <typename T>
	T dot(const vec4_T<T>& v1, const vec4_T<T>& v2)
	{
		return (v1.x * v2.x) + (v1.y * v2.y) + (v1.z * v2.z) + (v1.w * v2.w);
	}

	template <typename T, typename U>
	T dot(const vec4_T<T>& v1, const vec4_T<U>& v2)
	{
		return (v1.x * static_cast<T>(v2.x)) + (v1.y * static_cast<T>(v2.y)) + (v1.z * static_cast<T>(v2.z)) + (v1.w * static_cast<T>(v2.w));
	}

	// dot5
	template <typename T>
	T dot(const vec5_T<T>& v1, const vec5_T<T>& v2)
	{
		return (v1.x * v2.x) + (v1.y * v2.y) + (v1.z * v2.z) + (v1.w * v2.w) + (v1.v * v2.v);
	}

	template <typename T, typename U>
	T dot(const vec5_T<T>& v1, const vec5_T<U>& v2)
	{
		return (v1.x * static_cast<T>(v2.x)) + (v1.y * static_cast<T>(v2.y)) + (v1.z * static_cast<T>(v2.z)) + (v1.w * static_cast<T>(v2.w)) + (v1.v * static_cast<T>(v2.v));
	}

	// length2
	template <typename T>
	T length(const vec2_T<T>& v)
	{
		return static_cast<T>(std::sqrt(dot(v, v)));
	}

	// length3
	template <typename T>
	T length(const vec3_T<T>& v)
	{
		return static_cast<T>(std::sqrt(dot(v, v)));
	}

	// length4
	template <typename T>
	T length(const vec4_T<T>& v)
	{
		return static_cast<T>(std::sqrt(dot(v, v)));
	}

	// length5
	template <typename T>
	T length(const vec5_T<T>& v)
	{
		return static_cast<T>(std::sqrt(dot(v, v)));
	}

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
	template <typename T>
	vec4_T<T> reflect(const vec4_T<T>& I, const vec4_T<T>& N)
	{
		return I - N * dot(N, I) * static_cast<T>(2);
	}

	template <typename T, typename U>
	vec4_T<T> reflect(const vec4_T<T>& I, const vec4_T<U>& N)
	{
		return I - N * dot(N, I) * static_cast<T>(2);
	}

	// normalize2
	template <typename T>
	vec2_T<T> normalize(const vec2_T<T>& v)
	{
		static_assert(std::numeric_limits<T>::is_iec559, "'normalize' accepts only floating-point inputs");
		return v * inversesqrt(dot(v, v));
	}

	// normalize3
	template <typename T>
	vec3_T<T> normalize(const vec3_T<T>& v)
	{
		static_assert(std::numeric_limits<T>::is_iec559, "'normalize' accepts only floating-point inputs");
		return v * inversesqrt(dot(v, v));
	}

	// normalize4
	template <typename T>
	vec4_T<T> normalize(const vec4_T<T>& v)
	{
		static_assert(std::numeric_limits<T>::is_iec559, "'normalize' accepts only floating-point inputs");
		return v * inversesqrt(dot(v, v));
	}

	// normalize5
	template <typename T>
	vec5_T<T> normalize(const vec5_T<T>& v)
	{
		static_assert(std::numeric_limits<T>::is_iec559, "'normalize' accepts only floating-point inputs");
		return v * inversesqrt(dot(v, v));
	}
}
