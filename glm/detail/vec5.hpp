#pragma once
#include "vec4.hpp"

namespace glm
{
	template <typename T>
	class vec5_T
	{
	public:
		union
		{
			struct { T x, y, z, w, v; };
		};

		vec5_T() {}
		vec5_T(T _x, T _y, T _z, T _w, T _v) : x(_x), y(_y), z(_z), w(_w), v(_v) {}
		vec5_T(const vec5_T& v) : x(v.x), y(v.y), z(v.z), w(v.w), v(v.v) {}
		explicit vec5_T(T _a) : vec5_T(_a, _a, _a, _a, _a) {}
		template <typename T> explicit vec5_T(const vec5_T<T>& p) : x(T(p.x)), y(T(p.y)), z(T(p.z)), w(T(p.w)), v(T(p.v)) {}
		template <typename T> explicit vec5_T(const vec4_T<T>& xyzw, T _v) : x(T(xyzw.x)), y(T(xyzw.y)), z(T(xyzw.z)), w(T(xyzw.w)), v(T(_v)) {}
		template <typename P> explicit vec5_T(const P& p) : x((T)p.x), y((T)p.y), z((T)p.z), w((T)p.w), v((T)p.v) {}

		size_t length() const { return 5; }

		vec5_T<T> operator - () const { vec5_T<T> r; r.x = -this->x; r.y = -this->y; r.z = -this->z; r.w = -this->w; r.v = -this->v; return r; }

		vec5_T<T> operator + (const vec5_T<T>& p)	const { vec5_T<T> r; r.x = this->x + p.x; r.y = this->y + p.y; r.z = this->z + p.z;	r.w = this->w + p.w;	r.v = this->v + p.v;	return r; }
		vec5_T<T> operator - (const vec5_T<T>& p)	const { vec5_T<T> r; r.x = this->x - p.x; r.y = this->y - p.y; r.z = this->z - p.z;	r.w = this->w - p.w;	r.v = this->v - p.v;	return r; }
		vec5_T<T> operator * (const vec5_T<T>& p)	const { vec5_T<T> r; r.x = this->x * p.x; r.y = this->y * p.y; r.z = this->z * p.z;	r.w = this->w * p.w;	r.v = this->v * p.v;	return r; }
		vec5_T<T> operator / (const vec5_T<T>& p)	const { vec5_T<T> r; r.x = this->x / p.x; r.y = this->y / p.y; r.z = this->z / p.z;	r.w = this->w / p.w;	r.v = this->v / p.v;	return r; }
		vec5_T<T> operator + (const T     v)		const { vec5_T<T> r; r.x = this->x + v;   r.y = this->y + v;   r.z = this->z + v;	r.w = this->w + v;		r.v = this->v + v;	    return r; }
		vec5_T<T> operator - (const T     v)		const { vec5_T<T> r; r.x = this->x - v;   r.y = this->y - v;   r.z = this->z - v;	r.w = this->w - v;		r.v = this->v - v;	    return r; }
		vec5_T<T> operator * (const T     v)		const { vec5_T<T> r; r.x = this->x * v;   r.y = this->y * v;   r.z = this->z * v;	r.w = this->w * v;		r.v = this->v * v;	    return r; }
		vec5_T<T> operator / (const T     v)		const { vec5_T<T> r; r.x = this->x / v;   r.y = this->y / v;   r.z = this->z / v;	r.w = this->w / v;		r.v = this->v / v;	    return r; }

		template <typename U>
		vec5_T<T> operator + (const vec5_T<U>& p) const
		{
			return vec5_T<T>(
				this->x + static_cast<T>(p.x),
				this->y + static_cast<T>(p.y),
				this->z + static_cast<T>(p.z),
				this->w + static_cast<T>(p.w),
				this->v + static_cast<T>(p.v));
		}

		template <typename U>
		vec5_T<T> operator - (const vec5_T<U>& p) const
		{
			return vec5_T<T>(
				this->x - static_cast<T>(p.x),
				this->y - static_cast<T>(p.y),
				this->z - static_cast<T>(p.z),
				this->w - static_cast<T>(p.w),
				this->v - static_cast<T>(p.v));
		}

		template <typename U>
		vec5_T<T> operator * (const vec5_T<U>& p) const
		{
			return vec5_T<T>(
				this->x * static_cast<T>(p.x),
				this->y * static_cast<T>(p.y),
				this->z * static_cast<T>(p.z),
				this->w * static_cast<T>(p.w),
				this->v * static_cast<T>(p.v));
		}

		template <typename U>
		vec5_T<T> operator / (const vec5_T<U>& p) const
		{
			return vec5_T<T>(
				this->x / static_cast<T>(p.x),
				this->y / static_cast<T>(p.y),
				this->z / static_cast<T>(p.z),
				this->w / static_cast<T>(p.w),
				this->v / static_cast<T>(p.v));
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
			case 4:
				return v;
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
			case 4:
				return v;
			default:
				return x;
			}
		}

		vec5_T<T>& operator = (vec5_T<T> const& v)
		{
			this->x = v.x;
			this->y = v.y;
			this->z = v.z;
			this->w = v.w;
			this->v = v.v;
			return *this;
		}

		template<typename U>
		vec5_T<T>& operator = (vec5_T<U> const& v)
		{
			this->x = static_cast<T>(v.x);
			this->y = static_cast<T>(v.y);
			this->z = static_cast<T>(v.z);
			this->w = static_cast<T>(v.w);
			this->v = static_cast<T>(v.v);
			return *this;
		}

		template<typename U>
		vec5_T<T>& operator += (U scalar)
		{
			this->x += static_cast<T>(scalar);
			this->y += static_cast<T>(scalar);
			this->z += static_cast<T>(scalar);
			this->w += static_cast<T>(scalar);
			this->v += static_cast<T>(scalar);
			return *this;
		}

		template<typename U>
		vec5_T<T>& operator += (vec5_T<U> const& v)
		{
			this->x += static_cast<T>(v.x);
			this->y += static_cast<T>(v.y);
			this->z += static_cast<T>(v.z);
			this->w += static_cast<T>(v.w);
			this->v += static_cast<T>(v.v);
			return *this;
		}

		template<typename U>
		vec5_T<T>& operator -= (U scalar)
		{
			this->x -= static_cast<T>(scalar);
			this->y -= static_cast<T>(scalar);
			this->z -= static_cast<T>(scalar);
			this->w -= static_cast<T>(scalar);
			this->v -= static_cast<T>(scalar);
			return *this;
		}

		template<typename U>
		vec5_T<T>& operator -= (vec5_T<U> const& v)
		{
			this->x -= static_cast<T>(v.x);
			this->y -= static_cast<T>(v.y);
			this->z -= static_cast<T>(v.z);
			this->w -= static_cast<T>(v.w);
			this->v -= static_cast<T>(v.v);
			return *this;
		}

		template<typename U>
		vec5_T<T>& operator *= (U scalar)
		{
			this->x *= static_cast<T>(scalar);
			this->y *= static_cast<T>(scalar);
			this->z *= static_cast<T>(scalar);
			this->w *= static_cast<T>(scalar);
			this->v *= static_cast<T>(scalar);
			return *this;
		}

		template<typename U>
		vec5_T<T>& operator *= (vec5_T<U> const& v)
		{
			this->x *= static_cast<T>(v.x);
			this->y *= static_cast<T>(v.y);
			this->z *= static_cast<T>(v.z);
			this->w *= static_cast<T>(v.w);
			this->v *= static_cast<T>(v.v);
			return *this;
		}

		template<typename U>
		vec5_T<T>& operator /= (U scalar)
		{
			this->x /= static_cast<T>(scalar);
			this->y /= static_cast<T>(scalar);
			this->z /= static_cast<T>(scalar);
			this->w /= static_cast<T>(scalar);
			this->v /= static_cast<T>(scalar);
			return *this;
		}

		template<typename U>
		vec5_T<T>& operator /= (vec5_T<U> const& v)
		{
			this->x /= static_cast<T>(v.x);
			this->y /= static_cast<T>(v.y);
			this->z /= static_cast<T>(v.z);
			this->w /= static_cast<T>(v.w);
			this->v /= static_cast<T>(v.v);
			return *this;
		}

		bool operator == (vec5_T<T> const& v) const
		{
			return this->x == v.x && this->y == v.y && this->z == v.z && this->w == v.w && this->v == v.v;
		}

		bool operator != (vec5_T<T> const& v) const
		{
			return !(*this == v);
		}
	};

	typedef vec5_T<float>			vec5f;
	typedef vec5_T<double>			vec5d;
	typedef vec5_T<int>				vec5i;
	typedef vec5_T<unsigned int>	vec5u;
	typedef vec5_T<float>			vec5;
}
