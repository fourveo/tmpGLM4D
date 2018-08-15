#pragma once
#include "vec2.hpp"
#include "vec3.hpp"

namespace glm
{
	template <typename T>
	class vec4_T
	{
	public:
		union
		{
			struct { T x, y, z, w; };
			struct { T r, g, b, a; };
			struct { T s, t, p, q; };
		};

		vec4_T() {}
		vec4_T(T _x, T _y, T _z, T _w) : x(_x), y(_y), z(_z), w(_w) {}
		vec4_T(const vec4_T& v) : x(v.x), y(v.y), z(v.z), w(v.w) {}
		explicit vec4_T(T _a) : vec4_T(_a, _a, _a, _a) {}
		template <typename T> explicit vec4_T(const vec4_T<T>& p) : x(T(p.x)), y(T(p.y)), z(T(p.z)), w(T(p.w)) {}
		template <typename T> explicit vec4_T(const vec3_T<T>& xyz, T _w) : x(T(xyz.x)), y(T(xyz.y)), z(T(xyz.z)), w(T(_w)) {}
		template <typename T> explicit vec4_T(const vec2_T<T>& xy, const vec2_T<T>& zw) : x(T(xy.x)), y(T(xy.y)), z(T(zw.x)), w(T(zw.y)) {}
		template <typename T> explicit vec4_T(const vec2_T<T>& xy, T _z, T _w) : x(T(xy.x)), y(T(xy.y)), z(T(_z)), w(T(_w)) {}
		template <typename P> explicit vec4_T(const P& p) : x((T)p.x), y((T)p.y), z((T)p.z), w((T)p.w) {}

		size_t length() const { return 4; }

		vec4_T<T> operator - () const { vec4_T<T> r; r.x = -this->x; r.y = -this->y; r.z = -this->z; r.w = -this->w; return r; }

		vec4_T<T> operator + (const vec4_T<T>& p)	const { vec4_T<T> r; r.x = this->x + p.x; r.y = this->y + p.y; r.z = this->z + p.z;	r.w = this->w + p.w;	return r; }
		vec4_T<T> operator - (const vec4_T<T>& p)	const { vec4_T<T> r; r.x = this->x - p.x; r.y = this->y - p.y; r.z = this->z - p.z;	r.w = this->w - p.w;	return r; }
		vec4_T<T> operator * (const vec4_T<T>& p)	const { vec4_T<T> r; r.x = this->x * p.x; r.y = this->y * p.y; r.z = this->z * p.z;	r.w = this->w * p.w;	return r; }
		vec4_T<T> operator / (const vec4_T<T>& p)	const { vec4_T<T> r; r.x = this->x / p.x; r.y = this->y / p.y; r.z = this->z / p.z;	r.w = this->w / p.w;	return r; }
		vec4_T<T> operator + (const T     v)		const { vec4_T<T> r; r.x = this->x + v;   r.y = this->y + v;   r.z = this->z + v;	r.w = this->w + v;	    return r; }
		vec4_T<T> operator - (const T     v)		const { vec4_T<T> r; r.x = this->x - v;   r.y = this->y - v;   r.z = this->z - v;	r.w = this->w - v;	    return r; }
		vec4_T<T> operator * (const T     v)		const { vec4_T<T> r; r.x = this->x * v;   r.y = this->y * v;   r.z = this->z * v;	r.w = this->w * v;	    return r; }
		vec4_T<T> operator / (const T     v)		const { vec4_T<T> r; r.x = this->x / v;   r.y = this->y / v;   r.z = this->z / v;	r.w = this->w / v;	    return r; }

		template <typename U>
		vec4_T<T> operator + (const vec4_T<U>& p) const
		{
			return vec4_T<T>(
				this->x + static_cast<T>(p.x),
				this->y + static_cast<T>(p.y),
				this->z + static_cast<T>(p.z),
				this->w + static_cast<T>(p.w));
		}

		template <typename U>
		vec4_T<T> operator - (const vec4_T<U>& p) const
		{
			return vec4_T<T>(
				this->x - static_cast<T>(p.x),
				this->y - static_cast<T>(p.y),
				this->z - static_cast<T>(p.z),
				this->w - static_cast<T>(p.w));
		}

		template <typename U>
		vec4_T<T> operator * (const vec4_T<U>& p) const
		{
			return vec4_T<T>(
				this->x * static_cast<T>(p.x),
				this->y * static_cast<T>(p.y),
				this->z * static_cast<T>(p.z),
				this->w * static_cast<T>(p.w));
		}

		template <typename U>
		vec4_T<T> operator / (const vec4_T<U>& p) const
		{
			return vec4_T<T>(
				this->x / static_cast<T>(p.x),
				this->y / static_cast<T>(p.y),
				this->z / static_cast<T>(p.z),
				this->w / static_cast<T>(p.w));
		}

		T& operator [] (size_t i)
		{
			assert(i >= 0 && i < this->length());
			switch (i)
			{
			case 0:
				return x;
			case 1:
				return y;
			case 2:
				return z;
			case 3:
				return w;
			default:
				return x;
			}
		}

		T const& operator [] (size_t i) const
		{
			assert(i >= 0 && i < this->length());
			switch (i)
			{
			case 0:
				return x;
			case 1:
				return y;
			case 2:
				return z;
			case 3:
				return w;
			default:
				return x;
			}
		}

		vec4_T<T>& operator = (vec4_T<T> const& v)
		{
			this->x = v.x;
			this->y = v.y;
			this->z = v.z;
			this->w = v.w;
			return *this;
		}

		template<typename U>
		vec4_T<T>& operator = (vec4_T<U> const& v)
		{
			this->x = static_cast<T>(v.x);
			this->y = static_cast<T>(v.y);
			this->z = static_cast<T>(v.z);
			this->w = static_cast<T>(v.w);
			return *this;
		}

		template<typename U>
		vec4_T<T>& operator += (U scalar)
		{
			this->x += static_cast<T>(scalar);
			this->y += static_cast<T>(scalar);
			this->z += static_cast<T>(scalar);
			this->w += static_cast<T>(scalar);
			return *this;
		}

		template<typename U>
		vec4_T<T>& operator += (vec4_T<U> const& v)
		{
			this->x += static_cast<T>(v.x);
			this->y += static_cast<T>(v.y);
			this->z += static_cast<T>(v.z);
			this->w += static_cast<T>(v.w);
			return *this;
		}

		template<typename U>
		vec4_T<T>& operator -= (U scalar)
		{
			this->x -= static_cast<T>(scalar);
			this->y -= static_cast<T>(scalar);
			this->z -= static_cast<T>(scalar);
			this->w -= static_cast<T>(scalar);
			return *this;
		}

		template<typename U>
		vec4_T<T>& operator -= (vec4_T<U> const& v)
		{
			this->x -= static_cast<T>(v.x);
			this->y -= static_cast<T>(v.y);
			this->z -= static_cast<T>(v.z);
			this->w -= static_cast<T>(v.w);
			return *this;
		}

		template<typename U>
		vec4_T<T>& operator *= (U scalar)
		{
			this->x *= static_cast<T>(scalar);
			this->y *= static_cast<T>(scalar);
			this->z *= static_cast<T>(scalar);
			this->w *= static_cast<T>(scalar);
			return *this;
		}

		template<typename U>
		vec4_T<T>& operator *= (vec4_T<U> const& v)
		{
			this->x *= static_cast<T>(v.x);
			this->y *= static_cast<T>(v.y);
			this->z *= static_cast<T>(v.z);
			this->w *= static_cast<T>(v.w);
			return *this;
		}

		template<typename U>
		vec4_T<T>& operator /= (U scalar)
		{
			this->x /= static_cast<T>(scalar);
			this->y /= static_cast<T>(scalar);
			this->z /= static_cast<T>(scalar);
			this->w /= static_cast<T>(scalar);
			return *this;
		}

		template<typename U>
		vec4_T<T>& operator /= (vec4_T<U> const& v)
		{
			this->x /= static_cast<T>(v.x);
			this->y /= static_cast<T>(v.y);
			this->z /= static_cast<T>(v.z);
			this->w /= static_cast<T>(v.w);
			return *this;
		}

		bool operator == (vec4_T<T> const& v) const
		{
			return this->x == v.x && this->y == v.y && this->z == v.z && this->w == v.w;
		}

		bool operator != (vec4_T<T> const& v) const
		{
			return !(*this == v);
		}
	};

	typedef vec4_T<float>			vec4f;
	typedef vec4_T<double>			vec4d;
	typedef vec4_T<int>				vec4i;
	typedef vec4_T<unsigned int>	vec4u;
	typedef vec4_T<float>			vec4;
}
