#pragma once

namespace glm
{
	template <typename T>
	class vec2_T
	{
	public:
		union
		{
			struct { T x, y; };
			struct { T u, v; };
		};

		vec2_T() {}
		vec2_T(T _x, T _y) : x(_x), y(_y) {}
		vec2_T(const vec2_T& v) : x(v.x), y(v.y) {}
		explicit vec2_T(T _a) : vec2_T(_a, _a, _a) {}
		template <typename T> explicit vec2_T(const vec2_T<T>& p) : x(T(p.x)), y(T(p.y)) {}
		template <typename P> explicit vec2_T(const P& p) : x((T)p.x), y((T)p.y) {}

		size_t length() const { return 2; }

		vec2_T operator - () const { vec2_T r; r.x = -x; r.y = -y; return r; }

		vec2_T operator + (const vec2_T& p) const { vec2_T r; r.x = x + p.x; r.y = y + p.y;	return r; }
		vec2_T operator - (const vec2_T& p) const { vec2_T r; r.x = x - p.x; r.y = y - p.y;	return r; }
		vec2_T operator * (const vec2_T& p) const { vec2_T r; r.x = x * p.x; r.y = y * p.y;	return r; }
		vec2_T operator / (const vec2_T& p) const { vec2_T r; r.x = x / p.x; r.y = y / p.y;	return r; }
		vec2_T operator + (const T     v)	const { vec2_T r; r.x = x + v;   r.y = y + v;   return r; }
		vec2_T operator - (const T     v)	const { vec2_T r; r.x = x - v;   r.y = y - v;   return r; }
		vec2_T operator * (const T     v)	const { vec2_T r; r.x = x * v;   r.y = y * v;   return r; }
		vec2_T operator / (const T     v)	const { vec2_T r; r.x = x / v;   r.y = y / v;   return r; }

		T& operator [] (size_t i)
		{
			assert(i >= 0 && i < this->length());
			switch (i)
			{
			case 0:
				return x;
			case 1:
				return y;
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
			default:
				return x;
			}
		}

		vec2_T<T>& operator = (vec2_T<T> const& v)
		{
			this->x = v.x;
			this->y = v.y;
			return *this;
		}

		template<typename U>
		vec2_T<T>& operator = (vec2_T<U> const& v)
		{
			this->x = static_cast<T>(v.x);
			this->y = static_cast<T>(v.y);
			return *this;
		}

		template<typename U>
		vec2_T<T>& operator += (U scalar)
		{
			this->x += static_cast<T>(scalar);
			this->y += static_cast<T>(scalar);
			return *this;
		}

		template<typename U>
		vec2_T<T>& operator += (vec2_T<U> const& v)
		{
			this->x += static_cast<T>(v.x);
			this->y += static_cast<T>(v.y);
			return *this;
		}

		template<typename U>
		vec2_T<T>& operator -= (U scalar)
		{
			this->x -= static_cast<T>(scalar);
			this->y -= static_cast<T>(scalar);
			return *this;
		}

		template<typename U>
		vec2_T<T>& operator -= (vec2_T<U> const& v)
		{
			this->x -= static_cast<T>(v.x);
			this->y -= static_cast<T>(v.y);
			return *this;
		}

		template<typename U>
		vec2_T<T>& operator *= (U scalar)
		{
			this->x *= static_cast<T>(scalar);
			this->y *= static_cast<T>(scalar);
			return *this;
		}

		template<typename U>
		vec2_T<T>& operator *= (vec2_T<U> const& v)
		{
			this->x *= static_cast<T>(v.x);
			this->y *= static_cast<T>(v.y);
			return *this;
		}

		template<typename U>
		vec2_T<T>& operator /= (U scalar)
		{
			this->x /= static_cast<T>(scalar);
			this->y /= static_cast<T>(scalar);
			return *this;
		}

		template<typename U>
		vec2_T<T>& operator /= (vec2_T<U> const& v)
		{
			this->x /= static_cast<T>(v.x);
			this->y /= static_cast<T>(v.y);
			return *this;
		}

		bool operator == (vec2_T<T> const& v) const
		{
			return this->x == v.x && this->y == v.y;
		}

		bool operator != (vec2_T<T> const& v) const
		{
			return !(*this == v);
		}
	};

	typedef vec2_T<float>			vec2f;
	typedef vec2_T<double>			vec2d;
	typedef vec2_T<int>				vec2i;
	typedef vec2_T<unsigned int>	vec2u;
	typedef vec2_T<float>			vec2;
}

