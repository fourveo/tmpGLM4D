#pragma once

namespace glm
{
	// template <typename T> class vec3;

	template <typename T>
	class vec3
	{
	public:
		union
		{
			struct { T x, y, z; };
			struct { T r, g, b; };
			struct { T u, v, w; };
		};

		vec3() {}
		vec3(T _x, T _y, T _z) : x(_x), y(_y), z(_z) {}
		vec3(const vec3& v) : x(v.x), y(v.y), z(v.z) {}
		explicit vec3(T _a) : vec3(_a, _a, _a) {}
		template <typename T> explicit vec3(const vec3<T>& p) : x(T(p.x)), y(T(p.y)), z(T(p.z)) {}
		template <typename P> explicit vec3(const P& p) : x((T)p.x), y((T)p.y), z((T)p.z) {}

		size_t length() const { return 3; }

		vec3 operator - () const { vec3 r; r.x = -x; r.y = -y; r.z = -z; return r; }

		vec3 operator + (const vec3& p) const { vec3 r; r.x = x + p.x; r.y = y + p.y; r.z = z + p.z;	return r; }
		vec3 operator - (const vec3& p) const { vec3 r; r.x = x - p.x; r.y = y - p.y; r.z = z - p.z;	return r; }
		vec3 operator * (const vec3& p) const { vec3 r; r.x = x * p.x; r.y = y * p.y; r.z = z * p.z;	return r; }
		vec3 operator / (const vec3& p) const { vec3 r; r.x = x / p.x; r.y = y / p.y; r.z = z / p.z;	return r; }
		vec3 operator + (const T     v) const { vec3 r; r.x = x + v;   r.y = y + v;   r.z = z + v;	    return r; }
		vec3 operator - (const T     v) const { vec3 r; r.x = x - v;   r.y = y - v;   r.z = z - v;	    return r; }
		vec3 operator * (const T     v) const { vec3 r; r.x = x * v;   r.y = y * v;   r.z = z * v;	    return r; }
		vec3 operator / (const T     v) const { vec3 r; r.x = x / v;   r.y = y / v;   r.z = z / v;	    return r; }

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
			default:
				return x;
			}
		}

		vec3<T>& operator = (vec3<T> const& v)
		{
			this->x = v.x;
			this->y = v.y;
			this->z = v.z;
			return *this;
		}

		template<typename U>
		vec3<T>& operator = (vec3<U> const& v)
		{
			this->x = static_cast<T>(v.x);
			this->y = static_cast<T>(v.y);
			this->z = static_cast<T>(v.z);
			return *this;
		}

		template<typename U>
		vec3<T>& operator += (U scalar)
		{
			this->x += static_cast<T>(scalar);
			this->y += static_cast<T>(scalar);
			this->z += static_cast<T>(scalar);
			return *this;
		}

		template<typename U>
		vec3<T>& operator += (vec3<U> const& v)
		{
			this->x += static_cast<T>(v.x);
			this->y += static_cast<T>(v.y);
			this->z += static_cast<T>(v.z);
			return *this;
		}

		template<typename U>
		vec3<T>& operator -= (U scalar)
		{
			this->x -= static_cast<T>(scalar);
			this->y -= static_cast<T>(scalar);
			this->z -= static_cast<T>(scalar);
			return *this;
		}

		template<typename U>
		vec3<T>& operator -= (vec3<U> const& v)
		{
			this->x -= static_cast<T>(v.x);
			this->y -= static_cast<T>(v.y);
			this->z -= static_cast<T>(v.z);
			return *this;
		}

		template<typename U>
		vec3<T>& operator *= (U scalar)
		{
			this->x *= static_cast<T>(scalar);
			this->y *= static_cast<T>(scalar);
			this->z *= static_cast<T>(scalar);
			return *this;
		}

		template<typename U>
		vec3<T>& operator *= (vec3<U> const& v)
		{
			this->x *= static_cast<T>(v.x);
			this->y *= static_cast<T>(v.y);
			this->z *= static_cast<T>(v.z);
			return *this;
		}

		template<typename U>
		vec3<T>& operator /= (U scalar)
		{
			this->x /= static_cast<T>(scalar);
			this->y /= static_cast<T>(scalar);
			this->z /= static_cast<T>(scalar);
			return *this;
		}

		template<typename U>
		vec3<T>& operator /= (vec3<U> const& v)
		{
			this->x /= static_cast<T>(v.x);
			this->y /= static_cast<T>(v.y);
			this->z /= static_cast<T>(v.z);
			return *this;
		}

		bool operator == (vec3<T> const& v) const
		{
			return this->x == v.x && this->y == v.y && this->z == v.z;
		}

		bool operator != (vec3<T> const& v) const
		{
			return !(*this == v);
		}
	};

	typedef vec3<float> vec3f;
	typedef vec3<double> vec3d;
	typedef vec3<int> vec3i;
	typedef vec3<unsigned int> vec3u;
}

typedef glm::vec3f vec3;
