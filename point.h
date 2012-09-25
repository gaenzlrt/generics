#ifndef GENERICS_POINT_H
#define GENERICS_POINT_H

namespace generics {
	template< class coord_t, int DIMENSIONS >
	struct Point {
		coord_t * coords;

		inline void swap(Point & other) {
			coord_t * h = coords;
			coords = other.coords;
			other.coords = h;
		}

		inline coord_t & operator[](int index) { return coords[index]; }
		inline const coord_t & operator[](int index) const { return coords[index]; }

		Point & operator=(const Point & other) {
			for (int i = 0 ; i < DIMENSIONS; ++i) coords[i] = other.coords[i];
			return *this;
		}

		Point & operator=(coord_t value) {
			for (int i = 0 ; i < DIMENSIONS; ++i) coords[i] = value;
			return *this;
		}

		inline Point & operator+=(const Point & other) {
			for (int i = 0 ; i < DIMENSIONS; ++i) coords[i] += other.coords[i];
			return *this;
		}

		inline Point & operator-=(const Point & other) {
			for (int i = 0 ; i < DIMENSIONS; ++i) coords[i] -= other.coords[i];
			return *this;
		}

		inline void negate() {
			for (int i = 0 ; i < DIMENSIONS; ++i) coords[i] = -coords[i];
		}

		inline coord_t manhattanDist(const Point< coord_t, DIMENSIONS > & other) {
			coord_t result = 0;
			for (int d = 0; d < DIMENSIONS; ++d)
				result += other[d] < coords[d] ? coords[d] - other[d] : other[d] - coords[0];
			return result;
		}

		Point() : coords(new coord_t[DIMENSIONS]) {}
		Point(const Point & other) : coords(new coord_t[DIMENSIONS]) {
			for (int i = 0 ; i < DIMENSIONS; ++i) coords[i] = other.coords[i];
		}
		Point(coord_t uniform) : coords(new coord_t[DIMENSIONS]) {
			for (int i = 0 ; i < DIMENSIONS; ++i) coords[i] = uniform;
		}

		~Point() { delete[] coords; }
	};

	template< class coord_t, int DIMENSIONS >
	inline Point< coord_t, DIMENSIONS > operator-(const Point< coord_t, DIMENSIONS > & a, const Point< coord_t, DIMENSIONS > & b) {
		Point< coord_t, DIMENSIONS > result;
		for (int i = 0 ; i < DIMENSIONS; ++i) result[i] = a[i] - b[i];

		return result;
	}

	template< class coord_t, int DIMENSIONS >
	inline Point< coord_t, DIMENSIONS > operator+(const Point< coord_t, DIMENSIONS > & a, const Point< coord_t, DIMENSIONS > & b) {
		Point< coord_t, DIMENSIONS >  result;
		for (int i = 0 ; i < DIMENSIONS; ++i) result[i] = a[i] + b[i];

		return result;
	}

}

#endif
