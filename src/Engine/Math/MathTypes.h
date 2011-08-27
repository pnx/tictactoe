/* MathTypes.h
 *
 *   Copyright (C) 2011  Henrik Hautakoski <henrik@fiktivkod.org>
 *
 *   This program is free software: you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation, either version 3 of the License, or
 *   (at your option) any later version.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef ENGINE_MATH_MATHTYPES_H
#define ENGINE_MATH_MATHTYPES_H

// Template for 2d cordinates
template <class T> class cord2 {

public :
	T x, y;

	cord2<T>()
	{
		cord2<T>(0, 0);
	}

	cord2<T>(T x, T y)
	{
		this->x = x;
		this->y = y;
	}

	inline cord2<T>& operator=(const cord2<T> val)
	{
		x = val.x;
		y = val.y;
		return *this;
	}

	inline bool operator==(const cord2<T> &val) const
	{
		return x == val.x && y == val.y;
	}

	inline bool operator!=(const cord2<T> &val) const
	{
		return !(x == val.x && y == val.y);
	}

	inline bool operator>(const cord2<T> &val) const
	{
		return x > val.x && y > val.y;
	}

	inline bool operator>=(const cord2<T> &val) const
	{
		return x >= val.x && y >= val.y;
	}

	inline bool operator<(const cord2<T> &val) const
	{
		return x < val.x && y < val.y;
	}

	inline bool operator<=(const cord2<T> &val) const
	{
		return x <= val.x && y <= val.y;
	}
};

typedef cord2<float> cord2f;

#endif /* ENGINE_MATH_MATHTYPES_H */